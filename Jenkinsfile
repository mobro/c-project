
node {
	stage 'Checkout'
		checkout scm

	stage 'Build'
		
                sh 'mkdir -p build'
                sh 'cd build && cmake .. && make'
	
	stage 'Execution'
		sh 'pwd && ./app/build/application'
	
	//stage 'Test'
		//sh 'cd fw/build && pwd && ls -la && ./runTests'
		//step([$class: 'XUnitBuilder', testTimeMargin: '3000', thresholdMode: 1, thresholds: [[$class: 'FailedThreshold', failureNewThreshold: '', failureThreshold: '', unstableNewThreshold: '', unstableThreshold: '0'], [$class: 'SkippedThreshold', failureNewThreshold: '', failureThreshold: '', unstableNewThreshold: '', unstableThreshold: '']], tools: [[$class: 'GoogleTestType', deleteOutputFiles: true, failIfNotNew: true, pattern: 'build/testresults.xml', skipNoTestFiles: false, stopProcessingIfError: true]]])
}
