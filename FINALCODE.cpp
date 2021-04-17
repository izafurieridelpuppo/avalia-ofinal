#include <iostream>
using namespace std;

//constante para definir a quantidade máxima de caracteres
#define LETRAS_MAX 10

//função que calcula a quantas vezes a tecla de deve ser pressionada
//para obter o caractere enviado como argumento
void tecla(char letra)
{
    // array bi dimensional que mapeia teclas númericas e as letras do alfabeto
    char mapa[8][4] = {
        {'a', 'b', 'c', ' '}, // referente a tecla 2
        {'d', 'e', 'f', ' '}, // referente a tecla 3
        {'g', 'h', 'i', ' '}, // referente a tecla 4
        {'j', 'k', 'l', ' '}, // referente a tecla 5
        {'m', 'n', 'o', ' '}, // referente a tecla 6
        {'p', 'q', 'r', 's'}, // referente a tecla 7
        {'t', 'u', 'v', ' '}, // referente a tecla 8
        {'w', 'x', 'y', 'z'}, // referente a tecla 9
    };

    int j = 0;
    int tecla = 0;
    int quantidade = 0;

    //loop para procurar a linha (tecla) e coluna (quantidade) do array bi dimensional que o caractere desejado está
    for (j = 0; j < 8 * 4; j++)
    {
        tecla = j / 4;
        quantidade = j % 4;
        if (letra == mapa[tecla][quantidade])
            break; // ao encontrar sai do loop
    }

    if (j == 8 * 4)
    {
        //se a caractere não encontrado, imprime um texto indicando o erro
        cout << "#?=?" << '\n';
    }
    else
    {
        //imprime a tecla e a quantidade de vezes a ser pressionada para obter o caractere
        //+2 e +1 são necessários porque o índice do array começa com 0
        cout << '#' << tecla + 2 << '=' << quantidade + 1 << '\n';
    }
}

int main()
{
    //array para guardar a palavra enviada pelo usuário
    char palavra[LETRAS_MAX];

    cout << "Informe a palavra:";
    // função da biblioteca iostream que recebe o array para guardar a entrada do usuário
    // e também tem um argumento opcional com o limite de caracteres a ser armazenado
    cin.getline(palavra, LETRAS_MAX + 1); //+1 é para considerar o carácter de terminação nulo '\0''

    //loop para calcular a tecla e quantidade de cada letra entrada pelo usuário
    for (int j = 0; j < LETRAS_MAX; j++)
    {
        if (palavra[j] == ' ' or palavra[j] == '\0')
        {
            //caso encontre um espaço ou o final da entrada do usário, interrompe o loop
            break;
        }
        else
        {
            //chama a função que faz o cálculo da tecla e quantidade
            tecla(palavra[j]);
        }
    }

    return 0;
}
