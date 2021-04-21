Projeto para matéria de Multimídia (SCC0561) para o curso de Ciências de Computação da USP São Carlos.

O sistema faz uma leitura de uma imagem `.bmp` e cria dois arquivos `.bmp`:
- Um arquivo exatamente igual ao original com o nome adicionado de `_copy`.
- Um arquivo com o nome adicionado de `_processed` que, para cada pixel da imagem, coloca a intensidade da coloração *red* em *blue* e da coloração *blue* em *red*.

Considerações:
- O `.bmp` deve ter BitsPerPixel = 24, pois a struct que representa um pixel utiliza 3 `unsigned char` (ou seja, 8 bits) para cada coloração.

## Execução
Primeiro é necessário compilar os arquivos com o comando:
```
make
```
Em seguida, basta executar passando o nome do arquivo `.bmp` que será lido sem extensão:
```
./main nome_do_arquivo
```
Exemplo:
```
make
./main colors
```

## Referências
https://medium.com/sysf/bits-to-bitmaps-a-simple-walkthrough-of-bmp-image-format-765dc6857393