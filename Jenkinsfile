
node {
	stage 'Checkout'
		checkout scm

	stage 'Build'
		
                sh 'mkdir -p build'
                sh 'cd build && cmake -DCMAKE_BUILD_TYPE=Debug .. && make && make c-project_coverage && make c-project_cobertura'
	
	stage 'Execution'
		sh 'cd build && pwd && ./app/build/application'
	
	stage 'Test'
		sh 'cd build && ./fw/build/runTests --gtest_output="xml:testresults.xml"'
		step([$class: 'XUnitBuilder', testTimeMargin: '3000', thresholdMode: 1, thresholds: [[$class: 'FailedThreshold', failureNewThreshold: '', failureThreshold: '', unstableNewThreshold: '', unstableThreshold: '0'], [$class: 'SkippedThreshold', failureNewThreshold: '', failureThreshold: '', unstableNewThreshold: '', unstableThreshold: '']], tools: [[$class: 'GoogleTestType', deleteOutputFiles: true, failIfNotNew: true, pattern: 'build/testresults.xml', skipNoTestFiles: false, stopProcessingIfError: true]]])
			
}
