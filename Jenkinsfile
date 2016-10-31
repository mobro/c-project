
node {
	stage 'Checkout'
		checkout scm

	stage 'Build'
                sh 'mkdir -p build'
                sh 'cd build && cmake .. && make'
	
	stage 'Test'
		sh 'cd fw/build'
		sh 'pwd'
		sh 'ls -la'
		sh './runTests --gtest_output="xml:testresults.xml"'
}
