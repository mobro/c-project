
node {
	stage 'Checkout'
		checkout scm

	stage 'Build'
		
                sh 'mkdir -p build'
                sh 'cd build && cmake .. && make'
	
	stage 'Execution'
		sh 'cd build && pwd && ./app/build/application'
	
	stage 'Test'
		sh 'cd build && ./fw/build/runTests --gtest_output="xml:testresults.xml" --gtest_output=xml:coverage.junit.xml'
		step([$class: 'XUnitBuilder', testTimeMargin: '3000', thresholdMode: 1, thresholds: [[$class: 'FailedThreshold', failureNewThreshold: '', failureThreshold: '', unstableNewThreshold: '', unstableThreshold: '0'], [$class: 'SkippedThreshold', failureNewThreshold: '', failureThreshold: '', unstableNewThreshold: '', unstableThreshold: '']], tools: [[$class: 'GoogleTestType', deleteOutputFiles: true, failIfNotNew: true, pattern: 'build/testresults.xml', skipNoTestFiles: false, stopProcessingIfError: true]]])
}
