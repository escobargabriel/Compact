
#include <stdio.h>
#include <stdlib.h>

#define tamanho 1000000

int main(void)
{
	char sequencia[tamanho], caracter;
	int i, j, n, quantidade, repete = 0;
/*
==========================PRIMEIRA DESCOMPACTAÇÃO==========================
*/
//inicializa arquivo de fluxo de dados para leitura
	FILE *arquivo_leitura;
//Abre o arquivo para leitura, verificando se a operação foi bem sucedida
	if((arquivo_leitura = fopen("felis_catus","rb")) == NULL)
	{
        printf("Erro ao abrir arquivo compactado!\n");
        exit(1);
  	}
//Atribui o conteudo enquanto existente do arquivo aberto para a string sequencia
    fscanf(arquivo_leitura, "%[^\n]", &sequencia);
//fecha o arquivo após a leitura
	fclose(arquivo_leitura);
//inicializa arquivo de fluxo para escrita
	FILE *arquivo_escrita;
//verifica se a operação de abertura do arquivo foi bem sucedida
    if((arquivo_escrita = fopen("felis_catus.txt","w+")) == NULL)
	{
        printf("Erro ao abrir o primeiro arquivo para descompactacao!\n");
        exit(1);
  	}
/*Efetua iteração de todo conteúdo da string "sequencia"
  buscando as combinações possíveis com 2 caracteres.
  As combinacoes de caracteres são substituidas por caracteres
  equivalentes de acordo com a tabela de equivalencia.

    '\n'                '\n'
    AA                  .
    CC                  ;
    GG                  (
    TT                  ?
    NN                  -
    AC                  *
    AG                  [
    AT                  @
    CA                  #
    CG                  $
    CT                  %
    GA                  _
    GC                  &
    GT                  +
    TA                  <
    TC                  >
    TG                  ]
    quant carac >=3     nº+caracter
*/
	for(i=0; sequencia[i] != '\0'; i++)
	{
//verifica se o caracter da posicao i é eu numero
        if(isdigit(sequencia[i]) != 0)
		{
            repete = atoi(sequencia+i);
//imprime a quantidade "repete" do caracter que esta depois do numero
            j = 1;
            while(j<repete)
			{
                fprintf(arquivo_escrita, "%c", sequencia[i+1]);
                j++;
            }
        }
        //se não for número, imprime o caracter
        else
		{
            fprintf(arquivo_escrita, "%c", sequencia[i]);

		}
	}
//fecha o arquivo apos a escrita
    fclose(arquivo_escrita);
/*
===========================SEGUNDA DESCOMPACTAÇÃO===========================
*/
//Abre o arquivo para leitura, verificando se a operação foi bem sucedida
    FILE *arquivo_leitura_2;
	if((arquivo_leitura_2 = fopen("felis_catus.txt","r")) == NULL)
	{
        printf("Erro ao abrir arquivo na segunda compactacao!\n");
        exit(1);
  	}
//Atribui o conteudo enquanto existente do arquivo aberto para a string sequencia
    fscanf(arquivo_leitura_2, "%[^\n]", &sequencia);
//fecha o arquivo após a leitura
	fclose(arquivo_leitura_2);
//inicializa arquivo de fluxo para escrita
	FILE *arquivo_escrita_2;
//verifica se a operação de abertura do arquivo foi bem sucedida
    if((arquivo_escrita_2 = fopen("felis_catus.txt","w+")) == NULL)
	{
        printf("Erro ao abrir arquivo!\n");
        exit(1);
  	}
/*Efetua iteração de todo conteudo da string sequencia
  buscando caracteres repetidos.
  Os caracteres repetidos são substituidos pelo numero de
  repeticoes e o caracter repetido, desde que a repeticao seja
  maior ou igual a 3
*/
	for(i = 0; sequencia[i] != '\0'; i++)
	{
		if(sequencia[i] == '.')
		{
            fprintf(arquivo_escrita, "AA");
		}
		else if(sequencia[i] == ';')
		{
            fprintf(arquivo_escrita, "CC");
		}
        else if(sequencia[i] == '(')
		{
            fprintf(arquivo_escrita, "GG");
		}
        else if(sequencia[i] == '?')
		{
			fprintf(arquivo_escrita, "TT");
		}
		else if(sequencia[i] == '-')
		{
            fprintf(arquivo_escrita, "NN");
		}
        else if(sequencia[i] == '*')
		{
			fprintf(arquivo_escrita, "AC");
		}
        else if(sequencia[i] == '[')
		{
			fprintf(arquivo_escrita, "AG");
		}
		else if(sequencia[i] == '@')
		{
			fprintf(arquivo_escrita, "AT");
		}
		else if(sequencia[i] == '#')
		{
			fprintf(arquivo_escrita, "CA");
		}
		else if(sequencia[i] == '$')
		{
			fprintf(arquivo_escrita, "CG");
		}
		else if(sequencia[i] == '%')
		{
			fprintf(arquivo_escrita, "CT");
		}
        else if(sequencia[i] == '_')
		{
			fprintf(arquivo_escrita, "GA");
		}
        else if(sequencia[i] == '&')
		{
			fprintf(arquivo_escrita, "GC");
		}
		else if(sequencia[i] == '+')
		{
			fprintf(arquivo_escrita, "GT");
		}
		else if(sequencia[i] == '<')
		{
			fprintf(arquivo_escrita, "TA");
		}
        else if(sequencia[i] == '>')
		{
			fprintf(arquivo_escrita, "TC");
		}
        else if(sequencia[i] == ']' )
		{
			fprintf(arquivo_escrita, "TG");
		}
        else if(sequencia[i] == '\n')
		{
			fprintf(arquivo_escrita, "\n");
		}
        else
		{
            fprintf(arquivo_escrita, "%c", sequencia[i]);
		}
    }
//fecha o arquivo apos escrever
    fclose(arquivo_escrita_2);
	return 0;
}
