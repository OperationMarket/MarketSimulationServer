#!groovy

pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                sh 'cmake CMakeLists.txt'
                sh 'make'
            }
        }
    }
}