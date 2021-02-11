pipeline {
    agent any
    triggers {
        githubPush()
      }
    stages {
        stage('Build') {
            steps {
                sh "mkdir -p build"
                dir ('build') {
                    // install conant dependencies
                    sh "conan install ../"
                    // run CMakeList from root folder and buid 
                    sh "cmake ../ && cmake --build ."
                    // build executable and run it
                    sh "./bin/CPPTemplate_Executable"

                    sh "./bin/CPPTemplate_benchmarks"
                    //sh "./apps/CPPJenkins_Executable"
                    sh "./bin/CPPTemplate_unit_tests"
                }   
            }
        }
        stage('Test') {
            steps {
                echo 'Testing....'
            }
        }
        stage('Deploy') {
            steps {
                echo 'Deploying....'
            }
        }
    }
}
