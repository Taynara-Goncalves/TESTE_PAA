// teste3.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

// O(N)


#include <iostream>
#include <vector>

using namespace std;

void ExibeTela(vector<int> vetor)
{
//PERCORRE E IMPRIME O VETOR
	for (int i = 0; i < vetor.size(); i++)
		cout << vetor[i] << " ";
	cout << "\n";
}

bool Valida(vector<int>& variaveis, int N, int valor)
{
	//FUNCAO COM OS PARAMETROS UTILIZADOS NO ALGORITMO
	int par = 0, impar = 0;
	//INICIALIZA COM 0 PARA FAZER O SOMATORIO DEPOIS
	//VERIFICA SE O INDICE E O VALOR SÃO PARES
	if (variaveis.size() % 2 == 0 && valor % 2 == 0)
		return true;
	//VERIFICA SE O INDICE E O VALOR SÃO IMPARES
	if (variaveis.size() % 2 != 0 && valor % 2 != 0)
		return true;
	//PERCORRE TODOS OS VALORES QUE ESTA NA VARIAVEL FAZENDO O SOMATORIO DO PAR E IMPAR
	for (int i = 0; i < variaveis.size(); i++)
		if (i % 2 == 0)
			par += variaveis[i];
		else
			impar += variaveis[i];
	//COMPARA QUAL É MAIOR
	if (par < impar)
		return true;
	return false;
}

void backtracking(vector<int>& variaveis, int N)
{
	//DEPOIS QUE PERCORRER TODOS OS VALORES CHEGA NESSA CONDIÇÃO E EXIBE AS VARIAVEIS ENCONTRADAS
	if (variaveis.size() == N)
		return ExibeTela(variaveis);
	//INSERIR OS VALORES
	for (int i = 1; i <= 5 * N; i++)
		if (Valida(variaveis, N, i))
		{
			//VERIFICO SE O VALOR QUE ESTOU INSERINDO NA POSIÇÃO É PAR OU IMPAR E SE O PAR É MENOR QUE O IMPAR
			variaveis.push_back(i); //INSERINDO VALOR
			//RECURSIVO PORQUE CHAMO ELE
			backtracking(variaveis, N);
			variaveis.pop_back();//RETIRO VALOR SE NÃO SATISFAZER A CONDICAO
		}
}

int main()
{
	int N = 2;
	vector<int> variaveis;
	backtracking(variaveis, N);
	return 0;
}



// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
