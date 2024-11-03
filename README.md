1º Trabalho Prático - Sistemas Operacionais
Este repositório contém a documentação e código para o desenvolvimento de um processador baseado na arquitetura de Von Neumann, inspirado na arquitetura MIPS, como parte do 1º Trabalho Prático da disciplina de Sistemas Operacionais do 6º período de Engenharia de Computação no CEFET-MG Campus Divinópolis.

Professor: Michel Pires Dias
Disciplina: Sistemas Operacionais

Introdução
O objetivo deste projeto é desenvolver um processador simplificado que implementa a arquitetura de Von Neumann. Embora a base seja a arquitetura MIPS, o processador implementado inclui apenas funcionalidades essenciais para criar uma versão minimalista de um CPU.

Contexto
Arquitetura de Von Neumann
A arquitetura de Von Neumann, ou Arquitetura de Princeton, é um modelo de computadores digitais, proposto por John Von Neumann em 1945, e serve de base para as arquiteturas modernas. Seus principais componentes incluem:

Unidade de Processamento: composta pela Unidade Lógica e Aritmética (ULA) e a Unidade de Controle.
Unidade de Memória: armazena dados e instruções do programa.
Mecanismos de Entrada/Saída (I/O): permite a interação com o ambiente externo.
Arquitetura MIPS
A arquitetura MIPS é baseada na família de arquiteturas RISC e é amplamente utilizada em contexto educacional devido à sua simplicidade. Com diversas versões, ela foi uma referência para outras arquiteturas RISC. Atualmente, a empresa MIPS Technologies está desenvolvendo uma nova arquitetura baseada na família RISC-V.

Componentes da CPU
A CPU implementada neste projeto é composta por três partes principais: ULA, Unidade de Controle e Registradores. O ciclo de execução de instruções ocorre em cinco etapas:

IF (Instruction Fetch): busca da próxima instrução.
ID (Instruction Decode): decodificação e identificação dos componentes necessários.
EX (Execute): execução de operações na ULA.
MEM (Memory Access): leitura/escrita na memória.
WB (Write Back): armazenamento do resultado.
A técnica de Pipeline permite a execução simultânea de instruções em estágios diferentes, aumentando a eficiência da CPU.

ULA (Unidade Lógica e Aritmética)
A ULA realiza operações aritméticas e lógicas e inclui uma flag de overflow, que indica se o resultado excede a capacidade de representação.

Operações Implementadas
Aritméticas: ADD, SUB, MUL, DIV
Controle de Fluxo: BEQ, BNE, BLT, BGT, BGTI, BLTI
Transferência de Dados: LW, LA, ST
Unidade de Controle (Control Unit)
A Unidade de Controle coordena a execução das instruções, determinando a sequência e os operandos utilizados em cada instrução.

Registradores
Os registradores servem para o armazenamento temporário de dados e informações de controle. Entre eles, temos:

Específicos: pc, mar, cr, epc, sr, hi, lo, ir
Uso Geral: zero, at, v0-v1, a0-a3, t0-t9, s0-s7, k0-k1, gp, sp, fp, ra
Estrutura de Memória
MEMORYCELL e MAINMEMORY
Essas estruturas gerenciam o armazenamento volátil (RAM), onde os dados temporários e as instruções em uso pela CPU são armazenados.

SECONDARY_MEMORY
Armazena programas e dados de longo prazo. A memória inclui funcionalidades para leitura, escrita e operações de inversão de leitura.

Instruções Suportadas
Aritméticas: add, sub, div, mult
Condicionais: beq, bne, bgt, bgti, blt, blti
Controle de Fluxo: j
Transferência de Dados: lw, sw, li, la
Saída: print
Além disso, o processador suporta a declaração de variáveis inteiras e vetores, bem como o uso de labels para controle de fluxo.
Exemplo de código em assembly:

asm
Copiar código
main:
  li $t0 0
  li $t1 10
  li $t3 100
  j loop

loop:
  print $t0
  add $t0 $zero $t1
  blt $t0 $t3 loop
Compilação e Execução
O projeto utiliza o CMake para facilitar o processo de compilação. Siga os passos abaixo para compilar e executar o código:
