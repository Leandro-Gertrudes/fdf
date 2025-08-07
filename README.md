
# 🗺️ FdF - Fil de Fer
A 42 project to render 3D maps in wireframe using 2D graphics.

## Table of Contents

1. [About the Project](#about-the-project)  
2. [Projection](#projection)    
3. [Bresenham's Algorithm](#bresenhams-algorithm)
4. [Extra](#extra)
5. [How to Use](#how-to-use)

Para ler em Português, [clique aqui](#pt-br)

# About the Project

FdF (Fil de Fer) is a project from 42 School where the goal is to create a program capable of displaying 3D height maps in a 2D window using a wireframe representation.

It takes `.fdf` files — which contain a grid of points with height values — and converts them into a 2D visual using mathematical projections to simulate a 3D view.

This project challenges students to work with file parsing, classic computer graphics algorithms (like Bresenham’s), 3D projections (such as isometric), and the MiniLibX, the lightweight graphics library provided by 42.

A real treat for math and geometry enthusiasts 😄

# Projection

What is a projection?  
A projection is a way to represent a 3D object on a 2D surface, like a computer screen. Since screens have no real depth, we simulate the illusion of volume using projection techniques.

The idea is to transform a space defined by dimensions `X Y Z` into a 2D image with dimensions `X Y`, while still preserving the perception of height and shape.

Think of holding a cube near a wall with the sun casting a shadow. That shadow is a projection — a 2D representation of a 3D object — and its shape depends on the angle and position of the cube.

There are a few types of projections:

### 🔹 Parallel Projection

The projection “rays” are parallel. Objects maintain their relative size regardless of distance. This type of projection is used when shape and proportion accuracy is more important than realistic depth.

**Examples:**
- Engineering blueprints
- CAD software (AutoCAD, SolidWorks)
- Grid-based games (e.g., Civilization II)
- Age of Empires II
- Stardew Valley (uses orthographic projection)

Visual example:

![image](https://jonatasalexandre.com.br/wp-content/uploads/2021/04/projeto-spda-dwg.jpg)

---

### 🔹 Isometric Projection  
*(A type of parallel projection)*

In isometric projection, all three axes (x, y, z) are displayed at equal angles (typically 30° or 120°), giving the illusion of depth while preserving proportions.

**Formula:**
```
x' = (x - y) · cos(30°)  
y' = (x + y) · sin(30°) - z
```

The `-z` is used because in MiniLibX the Y axis grows downward.

**Examples:**
- IKEA manuals
- Tactical RPGs
- Hades
- SimCity 2000
- Diablo II
- RollerCoaster Tycoon

**Example running in isometric mode:**

![isometric](/.images/isometric.png)

Hades gameplay example:

![hades](https://www.numerama.com/wp-content/uploads/2021/08/73b6c0aa-d0a3-4cfb-b9cd-48a97525a186.jpg)

---

### 🔹 Perspective Projection

Here, the rays converge toward a vanishing point. Objects farther away appear smaller, creating a more realistic depth.

**Formula:**
```
x' = x · (d / (d + z))  
y' = y · (d / (d + z))
```

**Examples:**
- Photography
- Renaissance art
- Film scenes
- Minecraft
- The Legend of Zelda: BOTW
- First/third-person games like Fortnite or GTA V

**Example running in perspective mode:**

![perspective](/.images/perspective.png)

Real-world example: Counter Strike Global Offensive  
Note the vanishing lines and box sizes.

![csgo](/.images/csgo.png)

# Bresenham's Algorithm

Bresenham’s Algorithm is a method to draw straight lines between two points on a grid of pixels using only integer math.

Each step decides which pixel to draw next, avoiding floating-point operations. It determines whether to move horizontally (x), vertically (y), or both to stay close to the ideal line.

**Example:**

![bresenham](https://www.middle-engine.com/images/2020-07-28-bresenhams-line-algorithm/03_bresenham-12x12-example.gif)

### Initialization

```c
void init_bresenham(t_bresenham *b, t_point a, t_point b_point)
{
    b->dx = abs(b_point.x - a.x);
    b->dy = abs(b_point.y - a.y);
    b->sx = direction(a.x, b_point.x);
    b->sy = direction(a.y, b_point.y);
    b->err = b->dx - b->dy;
}
```

**Key variables:**
- `dx`: horizontal distance between points
- `dy`: vertical distance
- `sx`: direction along X (1 or -1)
- `sy`: direction along Y (1 or -1)
- `err`: accumulated error, helps determine when to move vertically

### Line Drawing Logic

```c
b_vars.e2 = 2 * b_vars.err;
if (b_vars.e2 > -b_vars.dy) {
    b_vars.err -= b_vars.dy;
    a.x += b_vars.sx;
}
if (b_vars.e2 < b_vars.dx) {
    b_vars.err += b_vars.dx;
    a.y += b_vars.sy;
}
```

This allows you to plot an approximate line using only integers — ideal for pixel displays.

Imagine drawing from `(0, 0)` to `(5, 3)`. Bresenham's logic tells you when to move up or keep drawing horizontally to stay close to the true line.

# Extra

To earn bonus points, I added a feature that fills the mesh faces with color.  
Pressing **T** enables or disables face coloring.

To do this, I split each quad into two triangles and used **barycentric coordinates** — a method that determines whether a point is inside a triangle.

Why triangles?  
Because triangles are always planar, which simplifies filling. Quads, in 3D, can become twisted or non-planar.

---

Given a quad with vertices A, B, C, D:

- Form triangles ABC and ACD
- Loop over the bounding box of the triangle
- Use the barycentric formula to check if a point lies inside

**Formula:**

![formula](/.images/Formula.png)

The formula checks whether a point lies to the left or right of a line.

In our case, if a point is on the **left side** (i.e., all results negative or zero) for each of the triangle’s edges, then it's inside the triangle.

So if all three edge checks return negative (or zero), we fill that pixel.

**Final result with filling enabled:**

![fill](/.images/fill.png)

# How to Use

### Requirements
- Linux system
- GCC compiler

### Compiling

Run the following in the project directory:

```
make
```

### Running

To launch the program with an `.fdf` file:

```
./fdf maps/42.fdf
```

Replace `maps/42.fdf` with the path to your own `.fdf` file.

Instructions will appear on screen.  
Press **ESC** to exit.

Thanks for reading!

--
### pt-br

# 🗺️ FdF - Fil de Fer

Projeto da 42 para exibir mapas 3D em wireframe usando gráficos 2D.

##  Índice

1. [Sobre o Projeto](#sobre-o-projeto)  
2. [Projeção](#projeção)    
3. [Algoritmo de Bresenham](#algoritmo-de-bresenham)
4. [Extra](#Extra)
5. [How to use](#How-to-use)

# Sobre o Projeto

FdF (Fil de Fer) é um projeto da escola 42 cujo objetivo é criar um programa capaz de exibir mapas tridimensionais em forma de wireframe (grade de linhas) em uma janela gráfica.

A proposta é transformar arquivos .fdf contendo uma malha de pontos 3D (com valores de altura) em uma representação visual em 2D, aplicando projeções matemáticas para simular uma visualização tridimensional.

O projeto desafia o aluno a trabalhar com manipulação de arquivos, algoritmos gráficos clássicos (como o de Bresenham), projeções 3D (como a isométrica) e o uso da MinilibX, a biblioteca gráfica fornecida pela 42

Um deleite para os amantes de matemarica e geometria espacial :D

# Projeção

   O que é uma projeção?
   Uma projeção é uma forma de representar um objeto tridimensional (3D) em uma superfície bidimensional (2D), como a tela do computador. Como a tela não tem profundidade real, precisamos simular a noção de profundidade e volume usando técnicas de projeção.
   
   A ideia central da projeção é traduzir um espaço com dimenções 'X 'Y 'Z em uma imagem 2D com dimenções 'Y 'X sem perder completamente a percepção de forma, altura e posição dos objetos. 
   
   Imagine que você está segurando um objeto, como um cubo, perto de uma parede, e o sol está batendo diretamente nele. O cubo vai projetar uma sombra na parede.

   Essa sombra é uma projeção: uma representação bidimensional (na parede) de um objeto tridimensional (o cubo), e sombra gerada irá depender da posição e angulo do objeto.
   
   Existem alguns tipos de projeções:
   
   ### 🔹 Projeção paralela
   
   Os “raios” de projeção são paralelos. Não há distorção por distância, então todos os objetos, próximos ou distantes, parecem do mesmo tamanho. Usada quando a precisão de forma e proporção é mais importante do que o realismo visual.
   
   Exemplos reais:
   
   Desenhos técnicos / engenharia: plantas baixas, esquemas de circuitos.
   
   Design CAD (AutoCAD, SolidWorks): peças mecânicas em vista ortográfica.
   
   Mapas em grade: jogos de estratégia como Civilization II, onde cada tile é igual e não há ponto de fuga.
   
   Age of Empires II (modo padrão de visão): vista levemente inclinada, onde os objetos têm o mesmo tamanho mesmo estando longe.
   
   Stardew Valley: usa uma projeção ortogonal, que é uma forma de projeção paralela bem “reta”.

exemplo visual:

![imagem](https://jonatasalexandre.com.br/wp-content/uploads/2021/04/projeto-spda-dwg.jpg)

Software CAD

---

### 🔹 Projeção isométrica
(Tipo de projeção paralela)


   Uma forma especial de projeção paralela em que os três eixos (x, y, z) são mostrados com o mesmo peso visual normalmente em ângulos de 30° ou 120° entre si. Mantém as proporções e dá uma ilusão de profundidade.

Representado pela fórmula
   <pre>
x' = (x - y) · cos(30º)  
y' = (x + y) · sin(3θº) - z // subtrai Z pois na MLX a linha sobe de maneira inversamente proporcional ao valor de Y, originalmente seria + Z
</pre>
   
   Exemplos reais:
   
   Manual técnico de montagem: instruções da IKEA frequentemente usam isométrica.
   
   Mapas táticos ou sistemas de RPG de tabuleiro.

   Hades (estilizado, mas com base isométrica)
   
   SimCity 2000
   
   Diablo II
   
   RollerCoaster Tycoon

### Programa funcionando em isométrica

![isometric](/.images/isometric.png)

Agora um exemplo real com o jogo Hades

![jogo-Hades](https://www.numerama.com/wp-content/uploads/2021/08/73b6c0aa-d0a3-4cfb-b9cd-48a97525a186.jpg)

---

### 🔹 Projeção perspectiva

   Os “raios” convergem em um ponto de fuga. Objetos mais distantes parecem menores como vemos no mundo real. Isso cria uma sensação forte de profundidade.

Representado pela fórmula
   <pre>
x' = x · (d / (d + z))  // A fórmula alterada pois na MLX o Y é invertido (quanto maior mais baixo)
y' = y · (d / (d + z))
</pre>
   
   Exemplos reais:
   
   Fotografias reais
   
   Pinturas com perspectiva renascentista
   
   Cenas de filmes ou cinema
   
   The Legend of Zelda: Breath of the Wild
   
   Minecraft (modo de visão padrão)
   
   Qualquer jogo 3D em primeira ou terceira pessoa moderna, como Fortnite, GTA V, The Witcher 3

### Programa funcionando em perspectiva

![perspective](/.images/perspective.png)

Exemplo real: Counter Striker Global Offensive

Note o afunilamento das retas no chão e a diferença de uma mesma caixa vista por diferentes distâncias
![csgo](/.images/csgo.png)

# Algoritmo de Bresenham

O Algoritmo de Bresenham é uma calculo usado para desenhar linhas retas entre dois pontos em uma tela composta por pixels (ou coordenadas inteiras).

Cada passo do algoritmo decide qual pixel pintar para formar a linha. Como a tela é uma grade de pixels, você precisa decidir quando andar na horizontal (x), quando subir/descer (y) e como controlar a inclinação da linha. Sem usar números de ponto flutuante, apenas adições, subtrações e comparações.

Imagine que você está indo da esquerda para a direita (incrementando x). A cada passo, você precisa decidir:
- Devo manter o mesmo y (mesma linha)?
- Ou devo subir para a próxima linha (y+1)?

![imagem](https://www.middle-engine.com/images/2020-07-28-bresenhams-line-algorithm/03_bresenham-12x12-example.gif)

O algoritmo decide.

Vamos estuda-lo:

Primeiro eu uso uma função para iniciar as variáveis da struct do Bresenham.

<pre>void	init_bresenham(t_bresenham *b, t_point a, t_point b_point)
{
	b->dx = abs(b_point.x - a.x);             // Distância em X
	b->dy = abs(b_point.y - a.y);             // Distância em Y
	b->sx = direction(a.x, b_point.x);        // Direção de X (1 ou -1)
	b->sy = direction(a.y, b_point.y);        // Direção de Y (1 ou -1)
	b->err = b->dx - b->dy;                   // Erro acumulado inicial
}
</pre>

Nao entendeu? leia a versão mais longa ou [clique aqui](#A-formula) para ir para os cálculos.

<pre>
dx = abs(x1 - x0)

Distância horizontal entre os dois pontos.
Mede quantos passos a linha terá no eixo X.
O abs() garante que o valor seja positivo, independentemente da direção.
</pre>

<pre>
dy = abs(y1 - y0)
   
Distância vertical entre os dois pontos.
Mede quantos passos a linha terá no eixo Y.
Também é sempre positivo.
</pre>

<pre>
sx = direction(x0, x1)
   
Direção no eixo X — para onde a linha caminha no eixo X.
+1 se a linha vai da esquerda para a direita
-1 se vai da direita para a esquerda
direction(a, b) é uma função sua que retorna 1 se b > a, senão -1.
</pre>

<pre>
sy = direction(y0, y1)

Direção no eixo Y — para onde a linha caminha no eixo Y.
+1 se a linha sobe
-1 se a linha desce
</pre>

<pre>
err = dx - dy

Erro acumulado — essa é a “inteligência” do algoritmo.
Controla quando você deve dar um passo em Y, enquanto anda em X (ou vice-versa).
Se dx for maior que dy, significa que a linha é mais horizontal.
A cada passo, err é ajustado para refletir o desvio entre a linha ideal (real, com floats) e a linha que você está desenhando (com pixels).
</pre>

<pre>
e2 = 2 * err

Erro dobrado — evita divisões, ajuda na decisão dos próximos passos.
Usado para comparar com -dy e dx e decidir se vai mover em X e/ou Y.
</pre>

### A formula

<pre>
b_vars.e2 = 2 * b_vars.err;
if (b_vars.e2 > -b_vars.dy)
{
   b_vars.err -= b_vars.dy;
   a.x += b_vars.sx;
}
if (b_vars.e2 < b_vars.dx)
{
   b_vars.err += b_vars.dx;
   a.y += b_vars.sy;
}
</pre>

Explicação passo a passo
### 🔹b_vars.e2 = 2 * b_vars.err;
Multiplica o erro por 2 para evitar divisão ou ponto flutuante — isso segue a otimização do algoritmo original de Bresenham.


### 🔹Primeiro if: decide se deve mover em X
<pre>
   if (b_vars.e2 > -b_vars.dy)
{
    b_vars.err -= b_vars.dy;
    a.x += b_vars.sx;
}
</pre>

- Se o erro acumulado é grande o suficiente, significa que a linha está “descendo muito devagar”.
- Então, avançamos no eixo X para nos manter próximos da linha ideal.
- E ajustamos o erro, subtraindo dy, para refletir o movimento.
- sx pode ser 1 (direita) ou -1 (esquerda), dependendo da direção da linha.

### 🔹 Segundo if: decide se deve mover em Y
<pre>
   if (b_vars.e2 < b_vars.dx)
{
    b_vars.err += b_vars.dx;
    a.y += b_vars.sy;
}
</pre>
- Se o erro acumulado indica que estamos "subindo ou descendo pouco", então é hora de mover também em Y.
- Movemos a.y na direção correta (sy = 1 ou -1), e corrigimos o erro somando dx.

-> Exemplo prático:

Imagine que você quer desenhar uma linha de (0, 0) até (5, 3)

Você quer chegar em (5,3), mas só pode andar 1 pixel por vez.

Às vezes, andar só em X não te aproxima da linha real. Então o erro te diz: "Ei, você precisa subir um pouco agora!"

Esse erro acumulado não é exato, mas dá boas decisões de quando subir ou seguir reto — é isso que faz o algoritmo funcionar tão bem com números inteiros.

# Extra

Afim de ganhar pontos extras, o enunciado permitia que o aluno implementasse qualquer melhoria no projeto.
Eu implementei a pintura das faces do mapa, ao apertar T o mapa se pinta sozinho com ou sem cor, de acordo com a preferencia do usuário.

Para este fim, eu dividi cortei os quadrados ao meio em dois triângulos e eu usei o método das coordenadas baricêntricas, uma fórmula(outra, rs) que determina se um ponto está ou nao dentro de um triangulo, desta forma eu sei quais pixeis pintar.
Por que triàngulos? Porquê na eles sempre serão planos graficamente, o que torna a pintura mais fácil no código. Já os quadriláteros podem ser "dobrados" no espaço tridimencional, e pintar isso seria chato.

Vamos entender como isso funciona

Primeiro eu pego um quadrilátero do mapa e declaro suas declaro suas vertices como pontos A B C D, com elas eu tenho dois triangulos, um com ABC e outro ACD.

Agora que tenho dois triangulos, vou tratar um de cada vez.

Segue a fórmula

![formula](/.images/Formula.png)]

Mais precisamente, a fórmula nos diz se um ponto está à esquerda (resultado negativo) ou à direita (resultado positivo) de uma reta.
No nosso caso, a direção das retas (sentido dos vetores dos lados do triângulo) é tal que, se um ponto estiver dentro do triângulo, ele estará à esquerda de todas as arestas.
Isso significa que os três cálculos feitos com a fórmula devem retornar valores negativos ou zero.

Se isso acontecer, sabemos que o ponto está dentro do triângulo, e então podemos pintar esse pixel com a cor desejada.

Em resumo: para que um ponto seja considerado interno, todos os sinais devem ser negativos (ou zero). O valor zero significa que o ponto está exatamente sobre uma das arestas, o que também é aceitável.

resultado final com o preenchimento ativado

![fill](/.images/fill.png)

# How to use

Requisitos:
- Sistema linux
- compilador gcc

###  Compilando o projeto
No terminal, dentro da pasta do projeto:
```
Make
```

### executando
Para rodar o programa com um arquivo fdf use
```
./fdf maps/42.fdf
```
Substitua maps/42.fdf pelo caminho do seu arquivo .fdf.

Os comandos apararecerão na tela.

Quando quiser sair aperte ESQ

Obrigado!
