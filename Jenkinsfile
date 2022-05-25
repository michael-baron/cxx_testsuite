pipeline {
    agent {
        label 'master'
    }
    environment {
        KLOCWORK_BUILDSPEC = "kwinject.out"
        KLOCWORK_TABLES = "kwtables"
        KLOCWORK_URL = 'http://localhost:8082'
        KLOCWORK_PROJECT = "cxx_testsuite"
        KLOCWORK_LTOKEN = "/opt/klocwork/ltoken"
    }
    stages {
        stage('Full, clean compile & link') {
            steps {
                sh '''
                    kwinject make
                '''
            }
        }
        stage('Full static code analysis'){
			when {
				branch 'master'
			}
            steps {
                echo "Performing Integration Analysis"
                klocworkIntegrationStep1 (
                [
                    buildSpec: "${KLOCWORK_BUILDSPEC}",
                    tablesDir: "${KLOCWORK_TABLES}",
                    incrementalAnalysis: true,
                    ignoreCompileErrors: false,
                    importConfig: "",
                    additionalOpts: "--replace-path ${WORKSPACE}=workspace",
                    disableKwdeploy: true
                ]
                )
                echo "Performing Integration Load"
                klocworkIntegrationStep2 (
                serverConfig:[
                    tablesDir: "${KLOCWORK_TABLES}",
                    buildName: "${GIT_COMMIT}",
                    additionalOpts: ""
                ],
                reportConfig:[
                    displayChart: true,
                    chartHeight: "",
                    chartWidth: "",
                    query: "status:+Analyze,+Fix"
                ]
                )
                echo "Performing Quality Gateway Checks"
                klocworkQualityGateway(
                [
                    enableServerGateway: true, 
                    gatewayServerConfigs: [
                    [
                        conditionName: 'Open High Severity Issues', 
                        enableHTMLReporting: false, 
                        jobResult: 'unstable', 
                        query: 'status:+Analyze,+Fix severity:1,2', 
                        stopBuild: false, 
                        threshold: '1'
                    ]
                    ]
                ]
                )
            }
        }
		stage('Diff static code analysis'){
			when {
				not {
					branch 'master'
				}
			}
			steps {
				sh '''
                    git diff --name-only --diff-filter=d origin/master > diff_file_list.txt
                '''
				def output_list = readFile("output.txt")
				if (output_list.size() != 0) {
					echo "Performing CI Analysis"
					klocworkIncremental(
					  [
						additionalOpts: '', 
						buildSpec: 'kwinject.out', 
						cleanupProject: false, 
						diffAnalysisConfig: [
							diffFileList: 'diff_file_list.txt', 
							diffType: 'manual', 
							gitPreviousCommit: ""
						], 
						incrementalAnalysis: true, 
						projectDir: '', 
						reportFile: 'kw_results.xml',
						ciTool: "kwciagent"
					  ]
					)
					echo "Performing Quality Gateway Checks"
					klocworkQualityGateway(
					  [
						enableCiGateway: true, 
						gatewayCiConfigs: [
						  [
							enableHTMLReporting: true, 
							enabledStatuses: [
								analyze: true, 
								defer: true, 
								filter: true, 
								fix: true, 
								fixInLaterRelease: true, 
								fixInNextRelease: true, 
								ignore: true, 
								notAProblem: true
							], 
							failUnstable: true, 
							name: 'No New Issues (Any Status)', 
							reportFile: 'kw_results.xml', 
							threshold: '1'
						  ]
						]
					  ]
					)
				}
			}
		}
    }
} 
