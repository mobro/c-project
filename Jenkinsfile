
node {
	stage 'Checkout'
		checkout scm

	stage 'Build'
		sh 'rm -R build'
                sh 'mkdir -p build'
                sh 'cd build && cmake .. && make'
	
	stage 'Test'
		sh 'cd fw/build && pwd && ls -la && ./runTests --gtest_output="xml:testresults.xml" || true'
}
