#include <stdio.h>  // biblioteca de comunicaçao com o usuario
#include <stdlib.h>  // biblioteca de alocaçao com o usuario
#include <locale.h> // biblioteca de alocaçoes de texto por regiao 
#include <string.h>   // biblioteca responsavel por cuidar da string

int registro()
{   

    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    char ARQUIVO[40];
    char CPF  [40];
    char NOME [40];
    char SOBRENOME [40];
    char CARGO [40];

      
    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s" , CPF);
        
    strcpy(ARQUIVO, CPF); // Responsavel por copiar os valores das string
        

    FILE *file; // Cria o arquivo
    file = fopen(ARQUIVO, "w"); // cris o arquivo 
    fprintf(file,CPF); //salvo o valor da variavel 
    fclose(file); // fechar o arquivo  

    file = fopen(ARQUIVO, "a");
    fprintf(file,",");
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", NOME);

    file = fopen(ARQUIVO, "a");
    fprintf(file, NOME);
    fclose(file);

    file = fopen(ARQUIVO,"a"); 
    fprintf(file,",");
    fclose(file);
     

    printf("Digite o sobrenome a ser cadastrado:");
    scanf("%s", SOBRENOME);

    file = fopen(ARQUIVO,"a");
    fprintf(file,SOBRENOME);
    fclose(file);

    file = fopen(ARQUIVO,"a");
    fprintf(file,",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado:");
    scanf("%s", CARGO);
    
    file = fopen(ARQUIVO, "a");
    fprintf(file,CARGO);
    fclose(file);

  

    system("read"); 

}


int consultar()

{
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    char CPF [40];
    char conteudo [200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", CPF);

    FILE *file;
    file = fopen(CPF,"r");

 
       if(file == NULL)
  
{
    printf("Nao foi possivel abrir o arquivo, não localizado!.\n");
}

    while(fgets(conteudo, 200, file) != NULL)
    
    {
        printf("\nEssas são as informaçoes do usuario: ");
        printf("%s", conteudo);
        printf("\n\n");
    }

       system("read");
}

int deletar()
{

         char CPF[40];

         printf("Escolha o nome a ser deletado:");
         scanf("%s" , CPF);
         
        remove(CPF); 
        
        FILE *file;
        file = fopen(CPF, "r");
        fclose(file); 

        if(file == NULL)
        {
            printf("Usuario nao se encontra no sistema!. \n");
            system("read");
        }

}




int main()
{ 
    int opcao=0; //definindo variaveis
    int repetir=1;
    for (repetir=1; repetir=1;) 
    {    

        system("clear");
        setlocale(LC_ALL, "Portuguese");
    
        printf("### Cartorio da EBAC ###\n\n");
        printf("Escolha a opcao desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("opcao: "); // fim do menu

        scanf("%d", &opcao);
   
        system("clear");

            switch (opcao)
        {
                case 1:
                registro();
                break;
            
                case 2:
                consultar();
                break;

                case 3:
                deletar();
                break;
                
                case 4;
                printf("Obrigado por utilizar nosso sistema");
                return 0;
                break;
                
                default:
                printf("Essa opcao nao esta disponivel!\n");
                system("read");
                break;
    
        }


    }
}
