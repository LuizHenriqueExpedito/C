#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CANDIDATOS 3
#define MAX_ELEITORES 3
#define MAX_NOME 100 

int main()
{

    // Minhas Variáveis:
    int foraBob = 0, foraAlice = 0, foraCharlie = 0;
    int votosBob1 = 0, votosAlice1 = 0, votosCharlie1 = 0;

    char nome[MAX_NOME];

    printf("\nNomes dos candidatos para a eleição:\n");
    printf("[ Alice - Bob - Charlie ]\n\n");

    // string mCandidatos[MAX_ELEITORES][MAX_CANDIDATOS];
    char *mCandidatos[MAX_ELEITORES][MAX_CANDIDATOS];

    // Coletar os votos.
    for (int i = 0; i < MAX_ELEITORES; i++)
    {
        printf("Eleitor %d: Digite o nome de %d candidatos em ordem de sua preferência:\n", i + 1, MAX_CANDIDATOS);

        for (int j = 0; j < MAX_CANDIDATOS; j++)
        {
            printf("%dº: ", j + 1);
            fgets(nome, MAX_NOME, stdin); // Lê uma linha do stdin (incluindo espaços em branco) e armazena em nome.
                                          // Remove o caractere de nova linha ('\n') do final da string, se presente:
            nome[strcspn(nome, "\n")] = '\0';

            // mCandidatos[i][j] = get_string(NULL);

            // Alocar memória para armazenar o nome
            mCandidatos[i][j] = malloc(strlen(nome) + 1);
            if (mCandidatos[i][j] == NULL)
            {
                fprintf(stderr, "Erro de alocação de memória.\n");
                exit(EXIT_FAILURE);
            }

            // Copiar o nome para a memória alocada
            strcpy(mCandidatos[i][j], nome);
        }
    }

    // Mostrar a matriz com os candidatos.
    printf("\nMatriz preenchida:\n");
    printf("\n");
    for (int i = 0; i < MAX_ELEITORES; i++) // for (int i = 0; i < MAX_CANDIDATOS; i++)
    {
        printf("Votos eleitor %d:     ", i + 1);

        for (int j = 0; j < MAX_CANDIDATOS; j++)
        {
            printf("%s----------", mCandidatos[i][j]);
        }
        printf("\n");
    }

    // Contar os votos para cada candidato na primeira matriz.
    for (int i = 0; i < MAX_ELEITORES; i++)
    {
        for (int j = 0; j < MAX_CANDIDATOS; j++)
        {
            if (strcmp(mCandidatos[i][j], "Bob") == 0) // Reparar que aqui letras maísculas e minúsculas são diferentes. Ou seja, quando o eleitor cita seu cadidato ele deve escrever exatamente como o programa espera.
                votosBob1++;
            else if (strcmp(mCandidatos[i][j], "Alice") == 0)
                votosAlice1++;
            else if (strcmp(mCandidatos[i][j], "Charlie") == 0)
                votosCharlie1++;
        }
    }

    printf("\nVotos primeira Rodada:\n");
    printf("Alice    : %d votos\n", votosAlice1);
    printf("Bob      : %d votos\n", votosBob1);
    printf("Charlie  : %d votos\n", votosCharlie1);

    int somaTotal1 = votosAlice1 + votosBob1 + votosCharlie1;
    if (votosBob1 > (somaTotal1 / 2))
    {
        printf("\nVencedor da Eleição: Bob\n ");
    }
    else if (votosAlice1 > (somaTotal1 / 2))
    {
        printf("\nVencedor da Eleição: Alice\n");
    }
    else if (votosCharlie1 > (somaTotal1 / 2))
    {
        printf("\nVencedor da Eleição: Charlie\n");
    }

    else
    {
        printf("\nA eleição irá para o segundo turno!\n");

        // Lógica Rodrigo terceira Coluna da Matriz.
        for (int i = 0; i < MAX_ELEITORES; i++)
        {
            if (strcmp(mCandidatos[i][MAX_CANDIDATOS - 1], "Bob") == 0) // if (strcmp(mCandidatos[i][2], "Bob") == 0)
            {
                foraBob++;
                printf(" Bob");
            }
            else if (strcmp(mCandidatos[i][MAX_CANDIDATOS - 1], "Alice") == 0)
            {
                printf(" Alice");
                foraAlice++;
            }
            else if (strcmp(mCandidatos[i][MAX_CANDIDATOS - 1], "Charlie") == 0)
            {
                printf("Charlie;");
                foraCharlie++;
            }
        }
        printf("\nAparições na terceira coluna:\n");
        printf("Alice    : %d votos\n", foraAlice);
        printf("Bob      : %d votos\n", foraBob);
        printf("Charlie  : %d votos\n", foraCharlie);

        // Mostra quem vai ser eliminado.
        // MenosPreferido é aquele que teve menos Aparições na terceira coluna da matrix.
        char *menosPreferido = "";
        int votosDoMenosPreferido = 1000000;

        if (foraAlice != 0)
        {

            if (foraAlice < votosDoMenosPreferido)
            {

                votosDoMenosPreferido = foraAlice;
            }
        }
        if (foraCharlie != 0)
        {

            if (foraCharlie < votosDoMenosPreferido)
            {

                votosDoMenosPreferido = foraCharlie;
            }
        }
        if (foraBob != 0)
        {

            if (foraBob < votosDoMenosPreferido)
            {

                votosDoMenosPreferido = foraBob;
            }
        }

        // Apontaroes em C.

        if (foraBob == votosDoMenosPreferido)
        {
            menosPreferido = "Bob";
            printf("\nMenos Preferido na Terceira Coluna: Bob\n ");
        }
        else if (foraAlice == votosDoMenosPreferido)
        {
            menosPreferido = "Alice";
            printf("\nMenos Preferido na Terceira Coluna: Alice\n ");
        }
        else if (foraCharlie == votosDoMenosPreferido)
        {
            menosPreferido = "Charlie";
            printf("\nMenos Preferido na Terceira Coluna: Charlie\n ");
        }

        //MenosPreferido não participa da contagem!

        int votosAlice2 = votosAlice1;
        int votosBob2 = votosBob1;
        int votosCharlie2 = votosCharlie1;
        if (strcmp(menosPreferido, "") != 0)
        {

            for (int i = 0; i < MAX_ELEITORES; i++)
            {
                if (strcmp(mCandidatos[i][0], menosPreferido) == 0)
                {
                    if (strcmp(mCandidatos[i][1], "Bob") == 0 && strcmp("Bob", menosPreferido) != 0)
                    {
                        votosBob2++;
                        printf("\nABob ganhou voto.........................................\n ");
                    }
                    else if (strcmp(mCandidatos[i][1], "Alice") == 0 && strcmp("Alice", menosPreferido) != 0)
                    {
                        votosAlice2++;
                        printf("\nAlice ganhou voto.........................................\n ");
                    }
                    else if (strcmp(mCandidatos[i][1], "Charlie") == 0 && strcmp("Charlie", menosPreferido) != 0)
                    {
                        votosCharlie2++;
                        printf("\nCharlie ganhou voto.........................................\n ");
                    }
                }
            }
        }

        // Zerar os votos de quem foi elimidado para não atrapalhar o funcionamento do programa!
        if (strcmp("Alice", menosPreferido) == 0)
        {
            votosAlice2 = 0; // Para descartar os votos de Alice que já são inválidos. Assim Alice sai da disputa.
        }
        else if (strcmp("Bob", menosPreferido) == 0)
        {
            votosBob2 = 0; // Para descartar os votos de Bob que já são inválidos. Assim Bob sai da disputa.
        }
        else if (strcmp("Charlie", menosPreferido) == 0)
        {
            votosCharlie2 = 0; // Para descartar os votos de Charlie que já são inválidos. Assim Charlie sai da disputa.
        }

        int somaTotalVotosValidosNoTurnoCorrente = votosAlice2 + votosBob2 + votosCharlie2;
        //Nessa  parte os votos do menosPreferido estará valendo zero"...
        
        printf("Total da soma de votos: %d\n", somaTotalVotosValidosNoTurnoCorrente);

        if (votosBob2 > (somaTotalVotosValidosNoTurnoCorrente / 2))
        {
            printf("\nVencedor da Eleição: Bob\n ");
        }
        else if (votosAlice2 > (somaTotalVotosValidosNoTurnoCorrente / 2))
        {
            printf("\nVencedor da Eleição: Alice\n");
        }
        else if (votosCharlie2 > (somaTotalVotosValidosNoTurnoCorrente / 2))
        {
            printf("\nVencedor da Eleição: Charlie\n");
        }
        else
        {
            printf("\nNão foi Possível definir um vencedor\n");
            printf("\n O programa deve ser modificado para considerar um 3o turno...\n");
        }
    }

    for (int i = 0; i < MAX_ELEITORES; i++)
    {
        for (int j = 0; j < MAX_CANDIDATOS; j++)
            free(mCandidatos[i][j]); // Liberar a memória alocada
    }

    return 0;
}
