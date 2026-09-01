# minishell

Implementação de um shell interativo em C. O repositório se chama `minihell`, mas o executável gerado pelo `Makefile` é `minishell`.

O programa lê comandos do usuário, transforma a entrada em tokens e uma estrutura de execução, trata expansões e redirecionamentos e então executa comandos internos ou programas disponíveis no `PATH`.

## Requisitos

Para compilar a implementação atual, você precisa de:

- compilador C;
- `make`;
- GNU Readline e seus headers de desenvolvimento.

O projeto possui sua própria biblioteca auxiliar em `lib/`, compilada automaticamente pelo `Makefile`.

## Compilação

```bash
git clone https://github.com/MatheusViuge/minihell.git
cd minihell
make
```

O executável gerado é:

```text
minishell
```

Execute com:

```bash
./minishell
```

Ou use o target pronto (ele executa `clean` após compilar):

    make run

Outros comandos:

```bash
make clean
make fclean
make re
```

## Funcionalidades observadas

A implementação atual contém suporte para:

- leitura interativa de comandos com Readline;
- análise léxica e tokenização da entrada;
- construção e tratamento de uma estrutura de parsing;
- execução de programas localizados através do `PATH`;
- criação e gerenciamento de processos filhos;
- pipelines entre comandos;
- redirecionamentos de entrada e saída;
- expansão de valores do ambiente;
- tratamento de sinais;
- gerenciamento do ambiente do processo.

### Built-ins

Os **built-ins** (comandos implementados diretamente pelo próprio shell) presentes no código são:

```text
echo
cd
pwd
export
unset
env
exit
```

Exemplos:

```bash
pwd
cd /tmp
export NAME=Matheus
echo $NAME
env
```

Também é possível executar programas externos:

```bash
ls -la
grep main Makefile
```

E combinar comandos em pipelines/redirecionamentos suportados pelo parser:

```bash
ls | wc -l
```

## Como funciona internamente

O código está dividido em etapas relativamente claras:

```text
entrada
  ↓
lexer / tokens
  ↓
parser
  ↓
expansões e redirecionamentos
  ↓
resolução de built-in ou executável pelo PATH
  ↓
fork / pipes / execução
  ↓
status e próximo prompt
```

As principais áreas ficam em:

- `src/lexer/` — análise da entrada;
- `src/token/` — representação e manipulação de tokens;
- `src/Parser/` — parsing dos comandos;
- `src/expand/` — expansões;
- `src/redirects/` — pipes e redirecionamentos;
- `src/execucao/` — processos, PATH e execução;
- `src/builtins/` — comandos internos;
- `src/signal.c` — sinais.

## Limites

Este projeto implementa um subconjunto de comportamento de shell. Ele não deve ser tratado como substituto completo de Bash ou outro shell POSIX: apenas a sintaxe e os comportamentos efetivamente implementados pelo parser deste repositório estarão disponíveis.
