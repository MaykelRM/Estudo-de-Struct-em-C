#include <stdio.h>
#include <string.h>

#define MAX 100

int r;
int d, i = 0, im = 0;
float  listaMedia[MAX], mediaGeral = 0, media;
char nomeCompleto[100] = {0};

struct aluno
{
    char primeiroNome[100];
    char segundoNome[100];
    char nomeCompletoAluno[100];
    int id;
    float notas[3], media;    
};

struct aluno listaAluno[MAX];
struct aluno alunoGenerico;

void adicionarAlunos()
{
 
    printf("Digite o primeiro nome do aluno: ");
    scanf("%s", alunoGenerico.primeiroNome);
    
    printf("Digite o segundo nome: ");
    scanf("%s", alunoGenerico.segundoNome);
    
    strcat(nomeCompleto, alunoGenerico.primeiroNome);
    strcat(nomeCompleto, " ");
    strcat(nomeCompleto, alunoGenerico.segundoNome);

    strcpy(alunoGenerico.nomeCompletoAluno, nomeCompleto);

    printf("Digite o id do aluno: ");
    scanf("%d", &alunoGenerico.id);
   
    printf("Digite a primera nota do aluno: ");
    scanf("%f", &alunoGenerico.notas[0]);

    printf("Digite a segunda nota do aluno: ");
    scanf("%f", &alunoGenerico.notas[1]);

    printf("Digite a terceira nota do aluno: ");
    scanf("%f", &alunoGenerico.notas[2]);

    media = (alunoGenerico.notas[0] + alunoGenerico.notas[1] + alunoGenerico.notas[2])/3;

    printf("%.2f\n", media);

    listaMedia[im] = media;
    alunoGenerico.media = media;
    listaAluno[i] = alunoGenerico;
    i++;
    im++;
    media = 0;
    strcpy(nomeCompleto, "");

}

void calcularMedia(){

    float mediaGeralF = 0;

    r = im;

    while (r > 0)
    {
        mediaGeral += listaMedia[r - 1];
        r--;
    }
            
    mediaGeralF = mediaGeral / im;
    printf("Média Geral: %.2f\n", mediaGeralF);
             
    mediaGeralF = 0;
}

void buscarAluno(){


    int idBusca;
    int encontrado = 0;

    printf("Digite o id do aluno para exibir suas informações: ");
    scanf("%d", &idBusca);

    for(int j = 0; j < i; j++)
    {
        if(listaAluno[j].id == idBusca)
        {
            printf("Nome: %s\n", listaAluno[j].nomeCompletoAluno);
            printf("Média: %.2f\n", listaAluno[j].media);
            encontrado = 1;
            break;
        }
    }

    if(!encontrado)
    {
        printf("ID não existe\n");
    }
}


void listarAlunos(){

    int r;
    r = im;

    while (r > 0)
    {
        printf("Nome: %s\n", listaAluno[r - 1].nomeCompletoAluno);
        printf("Média: %.2f\n", listaAluno[r - 1].media);
        printf("ID: %d\n", listaAluno[r - 1].id);
        r--;
    }
    
}
   
int main()
{
    printf("==== MENU ====\n");
    printf("1: Adicionar Aluno\n");
    printf("2: Listar todos os alunos\n");
    printf("3; Buscar Aluno\n");
    printf("4: Média geral\n");
    printf("5: Sair\n");
    printf("Digite: ");
    scanf("%d", &d);


    while (d != 5)
    {
        switch (d)
        {
        case 1:
            adicionarAlunos();
            
            break;
        case 2:
            listarAlunos();
            break;
        case 3:
            buscarAluno();
            break;
        case 4: 
            calcularMedia();
            break;
        case 5:
            break;
        default:
            break;
        }

        printf("==== MENU ====\n");
        printf("1: Adicionar Aluno\n");
        printf("2: Listar todos os alunos\n");
        printf("3; Buscar Aluno\n");
        printf("4: Média geral\n");
        printf("5: Sair\n");
        printf("Digite: ");
        scanf("%d", &d);
    }
    
    printf("Sistema Finalizado!");

    return 0;
}
