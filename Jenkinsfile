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
	PATH = "/opt/klocwork/server/bin:/opt/klocwork/kwciagent/bin:${env.PATH}"
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
				echo "Performing CI Analysis"
				klocworkIncremental(
				    [
				    additionalOpts: '', 
				    buildSpec: 'kwinject.out', 
				    cleanupProject: false, 
				    differentialAnalysisConfig: [
				        diffFileList: 'diff_file_list.txt', 
				        diffType: 'manual', 
				        gitPreviousCommit: ''
				    ], 
				    incrementalAnalysis: true, 
				    projectDir: '', 
				    reportFile: 'kw_results.xml'
				    ]
				)
				echo "Performing Quality Gateway Checks"
				klocworkFailureCondition(
				    [
				        enableCiFailureCondition: true, 
				        failureConditionCiConfigs: [
				            [
				                diffFileList: 'diff_file_list.txt', 
				                enableHTMLReporting: true, 
				                failUnstable: true, 
				                name: 'New Issues', 
				                reportFile: 'kw_results.xml', 
				                threshold: '1', 
				                withDiffList: true
				            ]
				        ]
				    ]
				)
			}
		}
    }
} 
