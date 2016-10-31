
node {
	stage 'Checkout'
		checkout scm

	stage 'Build'
                sh 'mkdir -p build'
                sh 'cd build && cmake .. && make'
	
	stage 'Test'
		sh 'rm -R fw/build app/build'
		sh 'cd fw/build && pwd && ls -la && ./runTests --gtest_output="xml:testresults.xml" || true'
}
