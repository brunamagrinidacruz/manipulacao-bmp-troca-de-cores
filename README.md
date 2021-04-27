Projeto para matéria de Multimídia (SCC0561) para o curso de Ciências de Computação da USP São Carlos.

O sistema faz uma leitura de uma imagem `.bmp` e cria dois arquivos `.bmp`:
- Um arquivo exatamente igual ao original com o nome adicionado de `_copy`.
- Um arquivo com a imagem processada com o nome adicionado de `_processed`.

Os processamentos que podem ser realizados, ou seja, as operações, são:
1. Para cada pixel da imagem, coloca a intensidade da coloração *red* em *blue* e da coloração *blue* em *red*.
2. Para cada pixel da imagem, se mais de dois canais de cores tem uma intesidade maior que 127, o pixel tem todos os canais substituidos para o valor 255 (preto), caso contrário, todos os canais são substituidos para o valor 0 (branco).

Considerações:
- O `.bmp` deve ter BitsPerPixel = 24, pois a struct que representa um pixel utiliza 3 `unsigned char` (ou seja, 8 bits) para cada coloração.

## Execução
Primeiro é necessário compilar os arquivos com o comando:
```
make
```
Em seguida, basta executar passando o nome do arquivo `.bmp` que será lido sem extensão e a operação:
```
./main nome_do_arquivo [operacao]
```
Exemplo:
```
make
./main lenna 2 
```

## Referências
https://medium.com/sysf/bits-to-bitmaps-a-simple-walkthrough-of-bmp-image-format-765dc6857393