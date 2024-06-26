/* Declarative Pipeline
 * 
 * Example Jenkinsfiles using declarative pipeline syntax to compile a Raptor-Dev model, generate reports, run static analysis, archive results, execute tests, archive
 * results. This file will require multiple MathWorks Toolboxes and Raptor licenses to execute. Each section will have a comment with the required license. This file 
 * utilizes the MathWorks Jenkins plugin, only the Run MATLAB Command will be used here. MATLAB build scripts can redundant functionality to a JenkinsFiles, the unit test 
 * functionality requires the Simulink Test license. There is more control to the user writing the bootstrap test executer script. 
 * Adding new comment to test
 */
pipeline {
    agent any

    stages {
        stage('Set Raptor-Dev version') {
            steps {
                bat '"C:\\Program Files (x86)\\NewEagle\\Raptor\\raptor_conf_editor" CONFIG m:2023a.64 r:2024a_0.9.15337'
            }
        }

        stage('Setup build enviroment') {
            steps {
                runMATLABCommand(command: 'setup_build')
            }       
        }

        stage('Build Model') {
            steps {
                runMATLABCommand(command: 'slbuild(\'RaptorCheckExample\', \'ForceTopModelBuild\', true);')
            }       
        }

        // Comment out for now while dev
        // stage('Run Static Analysis') {
        //     steps {
        //         runMATLABCommand(command: 'raptor_stack_check_run(\'RaptorCheckExample\');')
        //     }
        // }
    }
    post {
        success {
            /* Grab Artifacts from Build */
            publishHTML (target : [allowMissing: false,
                 alwaysLinkToLastBuild: true,
                 keepAll: true,
                 reportDir: 'RaptorCheckExample_raptor_rtw\\html',
                 reportFiles: 'index.html',
                 reportName: 'Code Generation Report',
                 reportTitles: 'Code Generation Report'])
        }
    }
}