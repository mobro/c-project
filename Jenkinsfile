
node {
	stage 'Checkout'
		checkout scm

	stage 'Build'
                sh 'mkdir -p build'
                sh 'cd build && cmake .. && make'
	
	stage 'Test'
		sh 'cd fw/build && pwd && ls -la && ./runTests --quiet --no-verbose --gtest_output="xml:testresults.xml"'
}
