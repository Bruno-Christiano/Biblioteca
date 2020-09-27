#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <locale.h>

//** LISTA DE REGISTROS **
typedef struct Funcionario
{
    char nome[20], matricula[10], login[10], senha[10];

} Funcionario;

typedef struct Livro
{
    char nome[20], isbn[10];
    int quantidade, disp;

} Livro;

typedef struct Curso
{
    char nome[30], area[20];

} Curso;

typedef struct Aluno
{
    char nome[30], matricula[20];
    Curso curso[20];

} Aluno;

//** VARIAVEIS GLOBAIS **

Funcionario funcionarios[10];
Livro livros[10];
Aluno aluno[20];
Curso curso[20];

int indiceFuncionario = 0, indiceLivro = 0,
    indiceAluno = 0, indiceCurso = 0;

//** ASSINATURAS DOS PROCEDIMENTOS E FUNÇOES **

void FazerLogin();
void TelaMenuAdm();
void TelaMenuFuncionario();

void CadastrarFuncionario();
void CadastrarAluno();
void CadastrarLivros();
void EmprestarLivro();

void ListarLivros();
void ListarAluno();
void ListarFuncionario();

void LimparTela();

int ValidarLoginFuncionario(char login[10], char senha[10]);
void VerificarCamposLivros();

void encontrarAlunoCadastrado();

//** FUNÇÃO PRINCIPAL **
int main()
{
    // setlocale(LC_ALL, "portuguese");

    FazerLogin();

    return 0;
}

//** lISTA DE PROCEDIMENTOS **
void FazerLogin()
{
    int op, leftMenu, i = 0, contador = 0, tam = 0;
    char captura, user[10], pass[10], login[3], senha[3];

    do
    {
        printf("\n ---  LOGIN ---- \n ");
        printf("_________________ \n ");
        printf(" *** Usuário *** \n ");
        fflush(stdin);
        gets(user);
        printf(" *** Informe a Senha *** \n ");

        do
        {
            pass[i] = getch();
            if (pass[i] == 8 && i > 0) //Backspace
            {
                printf("\b \b");
                pass[i] = 0;
                i--;
            }
            else if (pass[i] == 13) // Enter
            {
                pass[i] = 0;
                i = 0;
                break;
            }
            else if (pass[i] != 8)
            {
                putchar('*');
                i++;
            }

        } while (i < 10); // TROCA DE CARACTERES, sTRINGS PARA UM MASCARA NAS SENHAS. CASO A SENHA PASSE DE 10 CARACTERES ELA EXECUTA O EVENTO.

        system("cls");
        /*
         c = strcmp(pass, "123"); 
        compPass = strcmp(user, "adm");
        */

        if (strcmp(user, "adm") == 0 && strcmp(pass, "123") == 0)
        {
            TelaMenuAdm();
        }
        else if (ValidarLoginFuncionario(user, pass) == 1)
        {
            TelaMenuFuncionario();
        }
        else
        {

            printf("\n Usuário ou Senha inválidos\n ");

            sleep(2);
        }
        contador++;
        if (contador >= 2)
        {
            printf("\n --- Muitas tentativas --- ");
            sleep(1);
            LimparTela();
            printf("** saindo do sistema ** ");
            sleep(1);
            exit(0);
        }

    } while (1); // login para adm ou funcionario entrar no menu correspondente.
}
//** FUNÇÃO  **
int ValidarLoginFuncionario(char user[10], char pass[10])
{

    for (int i = 0; i < indiceFuncionario; i++)
    {
        if (strcmp(user, funcionarios[i].login) == 0 && strcmp(pass, funcionarios[i].senha) == 0)
        {
            return 1;
        }
    }

    return 0;
}
//poderia ser feito um procedimento, pra verificação. mas to afim não. kkkk
void CadastrarFuncionario()
{
    int novoCadastro, pegaString;

    do
    {
        LimparTela();

        printf("\n ----- CADASTRAR FUNCIONARIO ----- ");
        do
        {
            printf("\n Informe o nome: ");
            fflush(stdin);
            gets(funcionarios[indiceFuncionario].nome);
            pegaString = strlen(funcionarios[indiceFuncionario].nome); //pegar a quantidade de caracteres digitado e atender as rn ou não.
            if (pegaString == 0)
            {
                printf(" \n --- Dados Inválidos! -- ");
                sleep(1);
                LimparTela();
            }

        } while (pegaString <= 0); //poderia ser feito um procedimento, pra verificação. mas to afim não. kkkk
        pegaString = 0;            //zerar a var cada vez que for fazer verficação de campos.
        do
        {
            printf("\n Informe a matricula: ");
            fflush(stdin);
            gets(funcionarios[indiceFuncionario].matricula);
            pegaString = strlen(funcionarios[indiceFuncionario].matricula);
            if (pegaString == 0)
            {
                printf(" \n --- Dados Inválidos! -- \n ");
                sleep(1);
                LimparTela();
            }

        } while (pegaString <= 0);
        pegaString = 0;
        do
        {
            printf("\n Informe o login: ");
            fflush(stdin);
            gets(funcionarios[indiceFuncionario].login);
            pegaString = strlen(funcionarios[indiceFuncionario].login);
            if (pegaString == 0)
            {
                printf(" \n --- Dados Inválidos! -- \n ");
                sleep(1);
                LimparTela();
            }

        } while (pegaString <= 0);
        pegaString = 0;
        do
        {
            printf("\n Informe a senha: ");
            fflush(stdin);
            gets(funcionarios[indiceFuncionario].senha);
            pegaString = strlen(funcionarios[indiceFuncionario].senha);
            if (pegaString == 0)
            {
                printf(" \n --- Dados Inválidos! -- \n ");
                sleep(1);
                LimparTela();
            }

        } while (pegaString <= 0);
        pegaString = 0;
        indiceFuncionario++;

        printf("\n ***** Cadastrado com sucesso! *****\n\n ");

        sleep(2);

        ListarFuncionario();

        printf("\n\n ----- [1]- Cadastrar Novamente || [0]- Menu Anterior -----\n ");
        scanf("%d", &novoCadastro);

    } while (novoCadastro != 0);
    //TelaMenuAdm();
}

void ListarFuncionario()
{
    printf("\n ----- LISTA DE FUNCIONARIOS -----");

    for (int i = 0; i < indiceFuncionario; i++)
    {
        printf("\n Nome:      %s", funcionarios[i].nome);
        printf("\n Matrícula: %s", funcionarios[i].matricula);
        printf("\n ______________________________________\n");
    }
}

void CadastrarLivros()
{
    int novoCadastro, pegaString;

    do
    {
        LimparTela();

        printf("\n ----- CADASTRAR LIVRO -----");
        do
        {
            printf("\n Informe o nome: ");
            fflush(stdin);
            gets(livros[indiceLivro].nome);
            pegaString = strlen(livros[indiceLivro].nome); //pegar a quantidade de caracteres digitado e atender as rn ou não.
            if (pegaString == 0)
            {
                printf(" \n --- Dados Inválidos! -- ");
                sleep(1);
                LimparTela();
            }

        } while (pegaString <= 0); //poderia ser feito um procedimento, pra verificação. mas to afim não. kkkk
        pegaString = 0;            //zerar a var cada vez que for fazer verficação de campos.
        do
        {
            printf("\n Informe a isbn: ");
            fflush(stdin);
            gets(livros[indiceLivro].isbn);
            pegaString = strlen(livros[indiceLivro].isbn); //pegar a quantidade de caracteres digitado e atender as rn ou não.
            if (pegaString == 0)
            {
                printf(" \n --- Dados Inválidos! -- ");
                sleep(1);
                LimparTela();
            }

        } while (pegaString <= 0); //poderia ser feito um procedimento, pra verificação. mas to afim não. kkkk
        pegaString = 0;            //zerar a var cada vez que for fazer verficação de campos.
        do
        {
            printf("\n Informe a quantidade: ");
            //fflush(stdin);
            scanf("%d", &livros[indiceLivro].quantidade);
            pegaString = livros[indiceLivro].quantidade; //pegar a quantidade de caracteres digitado e atender as rn ou não.
            if (pegaString <= 0)                         // tratar a verificação de quando o campo vazio for pressionado o ENTER.
            {
                printf(" \n --- Dados Inválidos! -- ");
                sleep(1);
                LimparTela();
            }

        } while (pegaString == 0); //poderia ser feito um procedimento, pra verificação. mas to afim não. kkkk
        pegaString = 0;            //zerar a var cada vez que for fazer verficação de campos.

        livros[indiceLivro].disp = 1;
        indiceLivro++;

        printf("\n ***** Cadastrado com sucesso! ***** ");

        sleep(2);

        ListarLivros();

        printf("\n\n ----- [1]- Cadastrar Novamente || [0]- Menu Anterior -----\n ");
        scanf("%d", &novoCadastro);

    } while (novoCadastro != 0);
}

void CadastrarAluno()
{
    int novoCadastro, pegaString;

    do
    {
        LimparTela();

        printf("\n ----- CADASTRAR ALUNO -----");

        do
        {
            printf("\n Informe o nome: ");
            fflush(stdin);
            gets(aluno[indiceAluno].nome);
            pegaString = strlen(aluno[indiceAluno].nome); //pegar a quantidade de caracteres digitado e atender as rn ou não.
            if (pegaString == 0)
            {
                printf(" \n --- Dados Inválidos! -- ");
                sleep(1);
                LimparTela();
            }

        } while (pegaString <= 0); //poderia ser feito um procedimento, pra verificação. mas to afim não. kkkk
        pegaString = 0;            //zerar a var cada vez que for fazer verficação de campos.
        do
        {
            printf("\n Informe a matrícula: ");
            fflush(stdin);
            gets(aluno[indiceAluno].matricula);
            pegaString = strlen(aluno[indiceAluno].matricula); //pegar a quantidade de caracteres digitado e atender as rn ou não.
            if (pegaString == 0)
            {
                printf(" \n --- Dados Inválidos! -- ");
                sleep(1);
                LimparTela();
            }

        } while (pegaString <= 0); //poderia ser feito um procedimento, pra verificação. mas to afim não. kkkk
        pegaString = 0;            //zerar a var cada vez que for fazer verficação de campos.
        do
        {
            printf("\n -- Informe o curso: -- ");
            printf("\n  Nome do curso:  ");
            fflush(stdin);
            gets(aluno[indiceAluno].curso[indiceAluno].nome);
            pegaString = strlen(aluno[indiceAluno].curso[indiceAluno].nome); //pegar a quantidade de caracteres digitado e atender as rn ou não.
            if (pegaString == 0)
            {
                printf(" \n --- Dados Inválidos! -- ");
                sleep(1);
                LimparTela();
            }

        } while (pegaString <= 0); //poderia ser feito um procedimento, pra verificação. mas to afim não. kkkk
        pegaString = 0;            //zerar a var cada vez que for fazer verficação de campos.
        do
        {
            printf("\n  Área :  ");
            fflush(stdin);
            gets(aluno[indiceAluno].curso[indiceAluno].area);
            pegaString = strlen(aluno[indiceAluno].curso[indiceAluno].area); //pegar a quantidade de caracteres digitado e atender as rn ou não.
            if (pegaString == 0)
            {
                printf(" \n --- Dados Inválidos! -- ");
                sleep(1);
                LimparTela();
            }

        } while (pegaString <= 0); //poderia ser feito um procedimento, pra verificação. mas to afim não. kkkk
        pegaString = 0;            //zerar a var cada vez que for fazer verficação de campos.

        // indiceCurso++;
        indiceAluno++;
        printf("\n ***** Cadastrado com sucesso! ***** ");

        sleep(2);

        ListarAluno();

        printf("\n\n ----- [1]- Cadastrar Novamente || [0]- Menu Anterior -----\n ");
        scanf("%d", &novoCadastro);

    } while (novoCadastro != 0);
}
/*--PROCEDIMENTO EMPRESTAR LIVROS */
/*
void EmprestarLivro()
{

	int i, id;
	int quantidade;
	int escolha;
	int quantidadeRestante;
	int idEmp = 0;
	int contador = 0;
	
	encontrarAlunoCadastrado();
    
     ListarLivros();
		
}

*/


void ListarAluno()
{
    // LimparTela();
    printf("\n ----- LISTA DE ALUNOS -----");

    for (int i = 0; i < indiceAluno; i++)
    {
        printf("\n Nome do Aluno: %s ", aluno[i].nome);
        printf("\n Matrícula: %s ", aluno[i].matricula);
        printf("\n Curso: %s ---- Área: %s ", aluno[i].curso[i].nome, aluno[i].curso[i].area);
        printf("\n ______________________________________\n");
    }
}

void ListarLivros()
{
    printf("\n ----- LISTA DE LIVROS -----");

    for (int i = 0; i < indiceLivro; i++)
    {
        printf("\n NOME: %s", livros[i].nome);
        printf("\n ISBN: %s", livros[i].isbn);
        printf("\n QUANTIDADE: %d", livros[i].quantidade);
        printf("\n status: %s", livros[i].disp == 1 ? "Disponível" : " Indisponível");
        printf("\n ______________________________________\n");
    }
}

void TelaMenuAdm()
{
    int opcao;

    while (1)
    {

        LimparTela();

        printf("\n\t BIBLIOTECA ALICE VIU ALICE VE - ADM \n\n");
        printf("1. Cadastro de Funcionário\n");
        printf("2. Cadastro de Livros\n");
        printf("3. Cadastro de Alunos \n");
        printf("4. Logoff\n");
        printf("0. Sair do Sistema\n");

        printf("Informe uma opção: ");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            CadastrarFuncionario();
            break;

        case 2:
            CadastrarLivros();
            break;

        case 3:
            CadastrarAluno();
            break;

        case 0:
            printf("\n *** EXIT ***");
            Sleep(2000);
            system("cls");
            exit(0);

            break;
        case 4:
            FazerLogin();
            break;

        default:
            printf("Digite uma opção válida\n");
            Sleep(1000);
        }
    }
}

void TelaMenuFuncionario()
{
    int opcao;

    while (1)
    {
        LimparTela();

        printf("\n\t BIBLIOTECA ALICE VIU, ALICE VÊ \n\n");
        printf("1. Cadastrar Aluno\n");
        printf("2. Realizar Empréstimo\n");
        printf("3. Realizar Devolução\n");
        printf("0. Logoff\n");
        printf("\n Informe uma opção: ");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            CadastrarAluno();
            break;

        case 2:
            EmprestarLivro();
            break;

        case 3:

            break;

        case 0:
            FazerLogin();
            break;

        default:
            printf("Digite uma opção válida\n");
            Sleep(1000);
        }
    }
}

//FUNÇÃO LIMPAR TELA
void LimparTela()
{
    system("cls");
}

/*
void VerificarCamposLivros()
{
    int pegaString;
      do
        {
        printf("\n Informe o nome: ");
        fflush(stdin);
        gets(livros[indiceLivro].nome);
        pegaString = strlen (livros[indiceLivro].nome);
        if (pegaString == 0)
        {
            printf (" \n --- Dados Inválidos! -- \n ");
            sleep(1);
            LimparTela();
        }

        } while (pegaString <= 0);
        pegaString=0;

//PROCEDIMENTO VÁLIDO, PARA SER USADO NOS CAMPOS DE VERIFICAÇÃO DO LIVRO
}

*/

void encontrarAlunoCadastrado() {
	char nomeAluno[20];
	char matriculaAluno[20];
	int count = 0;	
	system("cls");
	printf("\nPesquisar aluno");
	printf("\nInforme o nome do Aluno: ");
	fflush(stdin);
	gets(nomeAluno);
		
		
	for(count; count < indiceAluno; count++) {
		if( (strcmp(nomeAluno, aluno[count].nome) == 0) || (strcmp(matriculaAluno, aluno[count].matricula) == 0) ) {
			printf("\n Aluno %s encontrado!", aluno[count].nome);
			sleep(2);
			break;
		}
	}
		
	
}