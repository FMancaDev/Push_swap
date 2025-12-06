# Push_swap

This project involves sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed, one has to manipulate various types of algorithms and choose the most appropriate solution (optimized for data sorting) for optimized data sorting.

## 🚧 Project Dnder Development

I'm still working on the project, so please let me know if there are any mistakes.

## 🚀 Current Status: Phase 1 - Core Structure

I am currently building the foundational layer of the project. Before implementing the sorting logic or input validation, I focused on creating a robust data structure and the necessary utilities to manipulate the stack.

### 1. Data Structure Architecture
I chose to implement a **Doubly Linked List**. This structure was selected to optimize the traversal of the stack in both directions, which is critical for calculating the most efficient rotation path (top or bottom) during the sorting phase.

**The Node Structure:**
The structure is designed to hold not just the values, but also the metadata required for the cost-based sorting algorithm (Turk Algorithm).

```c
typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;
```

### NOTAS EM PORTUGUES
 - no inicio pensei em usar single link-list mas como tinha decidido fazer o bonus mudei para o double link-list pk tem uma armadilha para comandos como o rra ou o rrb pk para fazer rra preciso de encontrar o ultimo nó mas tbm preciso do penultimo nó para fazer:

```c
penultimo->next = NULL;
ultimo->next = head;
head = ultimo;
```
isso implicaria percorer a lista duas vezes ao mesmo tempo. já numa double link-list cada nó tem:
```c
next → próximo
prev → anterior
```
Se for ao último nó:
 - o penúltimo é last->prev
 - e o reverse rotate fica MUITO MAIS FACIL
```c
last = último nó
last->prev->next = NULL
last->next = head
head->prev = last
head = last
```
- Vou tentar explicar um pouco sobre a struct que usei:
```c
typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;
```
fiz esta struct porque queria algo que suportasse o algoritmo turk(ainda estou a estudalo) e aproveitar a vantagem que estou a usar double link-list:

- value - será o valor real introduzido no input<br>

- index - reprersenta a posicão do valor num array ordenado<br>

- push_cost - guarda o total de movimentos necessarios para mover o nó para a sua possicão na stack oposta permitindo escolher o movimento mais efiente
  
- above_median - indica se o nó esta na metade superior ou inferior da stack. serve para decidir a direcao da rotacão mais efiente:
```c
ra / rb - se tiver na metade de cima
rra / rrb - se tiver na metade de baixo
```
- cheapest - marca o nó com o menor movimento(push_cost), durante o algoritmo apenas um nó deve ter esta flag ativa — é o próximo nó a ser movido, garantindo que o algoritmo executa sempre a operação com menor moves

- target_node - Aponta para o nó da stack destino onde o elemento atual deve ser inserido para manter a ordem crescente.
EX: se estamos a mover valores da stack B para A, o target_node representa o local correto onde esse valor deve entrar.
```c
IMAGINA ESTAS STACKS:
      Stack A: 2 -> 4 -> 9
      Stack B: 7
O objetivo é inserir o nó 7 da stack B na posição correta da stack A para manter a ordem crescente.

O target_node de 7 é 9, porque ao inserir 7 antes de 9 a stack A permanece ordenada: 2 -> 4 -> 7 -> 9.
Este campo permite que o algoritmo saiba exatamente onde inserir cada elemento, sem percorrer a lista várias vezes.
```
```c
EXEMPLO COM IMGS PARA OS B*****

Stack A: 2 -> 4 -> 9
Stack B: 7
------------------------------
Stack A:        2 -> 4 -> 9
Stack B:             7
                     |
                     | target_node
                     v
Stack A (após push): 2 -> 4 -> 7 -> 9
```



- suporte ao turk:
c,d


