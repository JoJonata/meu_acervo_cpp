#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validaChave(char chave[]) {
    if (strlen(chave) != 26) {
        return 0;
    }

    int letras[26] = {0};

    for (int i = 0; i < 26; i++) {
        if (!isalpha(chave[i])) {
            return 0;
        }

        int index = toupper(chave[i]) - 'A';

        if (letras[index]) {
            return 0;
        }

        letras[index] = 1;
    }

    return 1;
}

void criptografaMensagem(char mensagem[], char chave[]) {
    int tamanho = strlen(mensagem);

    for (int i = 0; i < tamanho; i++) {
        if (isalpha(mensagem[i])) {
            int ehMaiuscula = isupper(mensagem[i]);
            char base = ehMaiuscula ? 'A' : 'a';
            int index = toupper(mensagem[i]) - 'A';
            mensagem[i] = chave[index];
            if (ehMaiuscula) {
                mensagem[i] = toupper(mensagem[i]);
            } else {
                mensagem[i] = tolower(mensagem[i]);
            }
        }
    }
}

int main() {
    char chave[27];
    printf("Informe a chave de substituição (26 letras): ");
    scanf("%s", chave);

    if (!validaChave(chave)) {
        printf("Chave inválida. A chave deve conter 26 letras do alfabeto sem repetições.\n");
        return 1;
    }

    char mensagem[1000];
    printf("Informe a mensagem a ser criptografada: ");
    getchar(); // Captura o caractere de nova linha após a leitura da chave
    fgets(mensagem, sizeof(mensagem), stdin);
    
    criptografaMensagem(mensagem, chave);
    printf("Mensagem criptografada: %s\n", mensagem);

    return 0;
}

