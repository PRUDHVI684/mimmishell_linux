#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>


int execute_builtin(char *argv[]);

int main(){
        //char buffer[]="ls -l date pwd";
        char *argv[100];
        char input[100];
        char *tk;
       while(1){
        printf("minishell>> ");
        if(fgets(input,sizeof(input),stdin)==NULL)
                break;

        input[strcspn(input,"\n")]='\0';
        if(strcmp(input,"exit")==0)
                        break;
        if(input[0]=='\0')
                continue;


        int ret,i=0;
        for(tk=strtok(input," ");(tk!=NULL);tk=strtok(NULL," ")){

                        argv[i]=tk;
                        //printf("tokens:%s\n",argv[i]);
                        i++;

                        }
        argv[i]=NULL;

        if(execute_builtin(argv))
                continue;



        ret=fork();

        if(ret==-1){
                perror("fork");
                continue;
        }
        else if(ret==0){

                 if (argv[2] != NULL && strcmp(argv[2], "<") == 0)
                {
                        if (argv[3] == NULL)
                        {
                           fprintf(stderr, "Missing filename\n");
                                _exit(1);
                        }

        int fd = open(argv[3], O_RDONLY);

        if (fd == -1)
        {
            perror("open");
            _exit(1);
        }

        if (dup2(fd, STDIN_FILENO) == -1)
        {
            perror("dup2");
            close(fd);
            _exit(1);
        }

        close(fd);

        // Remove "<" and "input.txt"
        int j = 2;

        while (argv[j + 2] != NULL)
        {
            argv[j] = argv[j + 2];
            j++;
        }

        argv[j] = NULL;
                }


                execvp(argv[0],argv);
                perror("execvp");
                _exit(127);


        }
        else{
                waitpid(ret,NULL,0);
        }

}
printf("shell terminated\n");
return 0;
}


int execute_builtin(char *argv[]){

        //for help command refering
        if (strcmp(argv[0], "help") == 0)
        {
        printf("Mini Shell Commands:\n");
        printf("  cd <directory>  - Change directory\n");
        printf("  pwd             - Display current directory\n");
        printf("  help            - Display help message\n");
        printf("  exit            - Exit the shell\n");

                return 1;

        }
        //for path get
        //
        if (strcmp(argv[0], "pwd") == 0)
        {
                char path[1024];

        if (getcwd(path, sizeof(path)) != NULL)
                printf("%s\n", path);
        else
                perror("pwd");

            return 1;
        }

        //for change dir

        if (strcmp(argv[0], "cd") == 0)
        {
            if (argv[1] == NULL)
        {
                fprintf(stderr, "cd: missing directory\n");
        }
        else if (chdir(argv[1]) == -1)
        {
                perror("cd");
        }

               return 1;
        }
        return 0;

}