/*
ALGORITMO DE COMPACTAÇÃO DE UMA CADEIA DE BASES NITROGENADAS DO DNA
*/

#include <stdio.h>
#include <stdlib.h>

#define tamanho 1000000

int main(void)
{
	char sequencia[tamanho], caracter;
	int i, n,u, quantidade, tamanhoreal, tamanhocompactado;
/*
==========================PRIMEIRA COMPACTAÇÃO==========================
*/
//inicializa arquivo de fluxo de dados para leitura
	FILE *arquivo_leitura;
//Abre o arquivo para leitura, verificando se a operação foi bem sucedida
	if((arquivo_leitura = fopen("felis_catus.txt","r")) == NULL)
	{
		printf("Erro ao abrir arquivo original!\n");
        exit(1);
  	}
//Atribui o conteudo enquanto existente do arquivo aberto para a string sequencia
	for (u = 0; u != EOF; u++)
	{
    fscanf(arquivo_leitura, "%c", sequencia);
	}
//fecha o arquivo após a leitura
	fclose(arquivo_leitura);
	printf("%d caracteres na sequencia original\n\n", strlen(sequencia));
//inicializa arquivo de fluxo para escrita
	FILE *arquivo_escrita;
//verifica se a operação de abertura do arquivo foi bem sucedida
    if((arquivo_escrita = fopen("felis_catus","w+b")) == NULL)
	{
		printf("Erro ao abrir o primeiro arquivo para escrita!\n");
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
	for(i = 0; sequencia[i] != '\0'; i = i + quantidade)
	{
		quantidade = 1;
		if(sequencia[i] == 'A' && sequencia[i+1] == 'A')
		{
			fprintf(arquivo_escrita, ".");
            quantidade = 2;
        }
		else if(sequencia[i] == 'C' && sequencia[i+1] == 'C')
		{
            fprintf(arquivo_escrita, ";");
            quantidade = 2;
        }
		else if(sequencia[i] == 'G' && sequencia[i+1] == 'G')
		{
			fprintf(arquivo_escrita, "(");
            quantidade = 2;
        }
        else if(sequencia[i] == 'T' && sequencia[i+1] == 'T')
		{
            fprintf(arquivo_escrita, "?");
            quantidade = 2;
        }
		else if(sequencia[i] == 'N' && sequencia[i+1] == 'N')
		{
            fprintf(arquivo_escrita, "-");
            quantidade = 2;
        }
        else if(sequencia[i] == 'A' && sequencia[i+1] == 'C')
		{
			fprintf(arquivo_escrita, "*");
            quantidade = 2;
        }
		else if(sequencia[i] == 'A' && sequencia[i+1] == 'G')
		{
            fprintf(arquivo_escrita, "[");
            quantidade = 2;
        }
        else if(sequencia[i] == 'A' && sequencia[i+1] == 'T')
		{
            fprintf(arquivo_escrita, "@");
            quantidade = 2;
        }
		else if(sequencia[i] == 'C' && sequencia[i+1] == 'A')
		{
            fprintf(arquivo_escrita, "#");
            quantidade = 2;
        }
		else if(sequencia[i] == 'C' && sequencia[i+1] == 'G')
		{
            fprintf(arquivo_escrita, "$");
            quantidade = 2;
        }
		else if(sequencia[i] == 'C' && sequencia[i+1] == 'T')
		{
            fprintf(arquivo_escrita, "%%");
            quantidade = 2;
        }
        else if(sequencia[i] == 'G' && sequencia[i+1] == 'A')
		{
            fprintf(arquivo_escrita, "_");
            quantidade = 2;
        }
		else if(sequencia[i] == 'G' && sequencia[i+1] == 'C')
		{
            fprintf(arquivo_escrita, "&");
            quantidade = 2;
        }
		else if(sequencia[i] == 'G' && sequencia[i+1] == 'T')
		{
            fprintf(arquivo_escrita, "+");
            quantidade = 2;
        }
        else if(sequencia[i] == 'T' && sequencia[i+1] == 'A')
		{
            fprintf(arquivo_escrita, "<");
            quantidade = 2;
        }
        else if(sequencia[i] == 'T' && sequencia[i+1] == 'C')
		{
            fprintf(arquivo_escrita, ">");
            quantidade = 2;
        }
        else if(sequencia[i] == 'T' && sequencia[i+1] == 'G')
		{
            fprintf(arquivo_escrita, "]");
            quantidade = 2;
        }
        else if(sequencia[i] == '\n')
		{
            fprintf(arquivo_escrita, "\n");
		}
        else
		{
            fprintf(arquivo_escrita, "%c%c", sequencia[i], sequencia[i+1]);
            quantidade = 2;
        }
	}
//fecha o arquivo apos a escrita
    fclose(arquivo_escrita);
/*
===========================SEGUNDA COMPACTAÇÃO===========================
*/
//Abre o arquivo para leitura, verificando se a operação foi bem sucedida
    FILE *arquivo_leitura_2;

	if((arquivo_leitura_2 = fopen("felis_catus","rb")) == NULL)
	{
        printf("Erro ao abrir arquivo na segunda compactacao!\n");
        exit(1);
  	}
//Atribui o conteudo enquanto existente do arquivo aberto para a string sequencia
	for (u = 0; u != EOF; u++)
	{
    fscanf(arquivo_leitura_2, "%c", sequencia);
	}
//fecha o arquivo após a leitura
	fclose(arquivo_leitura_2);
//inicializa arquivo de fluxo para escrita
FILE *arquivo_escrita_2;
//verifica se a operação de abertura do arquivo foi bem sucedida
    if((arquivo_escrita_2 = fopen("felis_catus","w+b")) == NULL)
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
	for(i=0; sequencia[i] != '\0'; i+=quantidade)
	{
		quantidade = 1;
		caracter = sequencia[i];
		for(n = i; caracter == sequencia[n+1]; n++)
		{
			quantidade++;
        }
        if(quantidade > 9)
		{
			quantidade = 9;
		}
        if(quantidade >= 3)
		{
            fprintf(arquivo_escrita_2,"%d%c", quantidade, caracter);
		}
        else if(sequencia[i] == '\n')
		{
            fprintf(arquivo_escrita_2, "\n");
		}
        else
		{
            fprintf(arquivo_escrita_2, "%c", caracter);
            quantidade = 1;
        }

	}
//fecha o arquivo apos escrever
    fclose(arquivo_escrita_2);
/************************************************/
	FILE *arquivo_leitura_3;

	if((arquivo_leitura_3 = fopen("felis_catus","rb")) == NULL)
	{
        printf("Erro ao abrir arquivo na segunda compactacao!\n");
        exit(1);
  	}
//Atribui o conteudo enquanto existente do arquivo aberto para a string sequencia
	for (u = 0; u != EOF; u++)
	{
    fscanf(arquivo_leitura_3, "%c", sequencia);
	}	
	printf("%d caracteres apos a compactacao\n\n", strlen(sequencia));
//fecha o arquivo após a leitura
	fclose(arquivo_leitura_2);
/************************************************/

	return 0;
}
