//Problema: qual é a maior capicua que se pode obter multiplicando dois números de dois dígitos?
//1. Verificar se um número é ou não capicúa (tricky)
//2. Calcular todas as capicuas múltiplas de números de 3 dígitos, enchendo uma tabela. (relativamente simples)
//3. Percorrer a tabela e encontrar o maior (elementar)
//Alternativamente, pode-se juntar os passos 2 e 3, calculando sobre apenas uma variável, substiuindo-a se o novo número for maior que o anterior. (implementado)

#include <iostream> //Apenas para poder dar cout do número que se obtém.


//multiplicações de números de 3 dígitos resultam sempre num número com 5 ou 6 dígitos
//100x100 = 10000, 999x999 = 998001, ou seja, para determinar se o número é ou não
//capicua, temos que ter em conta que este pode ter um número par ou ímpar de dígitos.
bool verifica(int n){
	//Determina quantos dígitos tem o número:
	int aux1 = n;
	int i = 0;
	for( ; aux1 != 0; i++)
		aux1 = aux1 / 10;
	//Neste momento sabemos que o número tem i dígitos.
	if(i % 2 == 0){ //Executa quando o número de dígitos é par, ou seja, 6.
		int aux2[6];
		for(int i = 0; i < 6; i++){
			aux2[i] = n % 10;
			n = n / 10; //espatifamos n, mas também não importa, pois fica guardado na tabela.
		}
		if(aux2[0] == aux2[5] && aux2[1] == aux2[4] && aux2[2] == aux2[3]) return true; //esta linha faz a verificação propriamente dita.
		else return false;
		
	} else{		//Executa quando o número de dígitos é ímpar, ou seja, 5.
		int aux2[5];
		for(int i = 0; i < 5; i++){
			aux2[i] = n % 10;
			n = n / 10;
		}
		if(aux2[0] == aux2[4] && aux2[1] == aux2[3]) return true;
		else return false;
	}
}

int main(){
	//Este bloco calcula a maior capicua, percorrendo todos os múltiplos de números de 3 dígitos.
	int capicuamaior = 0, ra = 0, rb = 0;
	for(int i = 100; i < 1000; i++)
		for(int j = 100; j < 1000; j++)
			if(verifica(i*j) && i*j > capicuamaior){capicuamaior = i*j; ra = i; rb = j;}

	
	std::cout << "A maior capicua resultante do produto de dois numeros de tres digitos e: " << capicuamaior << std::endl;
	std::cout << "Resultante do produto de " << ra << " e " << rb << std::endl;
	//Termina sem erros:
	return 0;
}
