# Matricula acadêmica
# Scorecard | [- - - - - - - - - -] | [100.0%]

## Recursos do projeto

### cadastro

- [x] Cadastrar alunos.
- [x] Cadastrar disciplinas.
- [x] Cadastrar professores.

### tratamento de dados

- [x] Realizar a matrícula de  um conjunto de alunos em um conjunto de disciplinas.
- [x] Vincular professores a disciplinas:  Vincular um professor a um conjunto de disciplinas.
- [x] Cancelar a matrícula de um conjunto de alunos de um conjunto de disciplinas.
- [x] Remover vínculo de professor de um conjunto de disciplinas.

### listagem

- [x] Imprimir a lista de todos os alunos.
- [x] Imprimir a lista de todas as disciplinas.
- [x] Imprimir a lista de todos os professores.
- [x] Imprimir a lista de disciplinas de um aluno.
- [x] Imprimir a lista de alunos em uma disciplina.
- [x] Imprimir a lista de todas as disciplinas ministradas por um professor.
- [x] Imprimir a lista de todos os professores vinculados a uma disciplina.

## Comentários do desenvolvedor [IMPORTANTE]
Este projeto foi construído usando o SO Ubuntu, mas inicialmente estava sendo desenvolvido em Windows nos computadores da universidade. Por este motivo foi necessário fazer algumas modificações para garantir a compatibilidade, entretanto funções como system("pause") ou system("cls") são diferentes entre cada SO, enquanto mexia no código utilizava a versão do meu sistema operacional mas para avaliação será enviado a versão windows.
Obs: na versão final a função system("pause") foi substituída por um scanf simples que solicita a entrada de um número qualquer, apenas para confirmação visual.
### AVISO
Nos computadores da universidade e nas aulas práticas era comum utiliarmos a função gets() para gravar strings em arrays, porém essa função é totalmente incompatível com sistemas atuais, como não sei de que forma será testado pelo professor optei por solucionar este problema com um scanf("%s") comum. Porém essa solução vem com resalvas como por exemplo não ser capaz de pegar espaços, sendo assim por favor, ao utilizar o sistema `UTILIZE PALAVRAS não frases`.

## Metodos extras

### recursos visuais

- [x] Reconstruir menu.
- [x] Lista dinâmica de seleção (alunos/disciplinas selecionados(as))
