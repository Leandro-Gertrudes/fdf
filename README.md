# 🗺️ FdF - Fil de Fer

Projeto da 42 para exibir mapas 3D em wireframe usando gráficos 2D.

##  Índice

1. [Sobre o Projeto](#sobre-o-projeto)  
2. [Projeção](#projeção)    
3. [Algoritmo de Bresenham](#algoritmo-de-bresenham)  

# Sobre o Projeto

FdF (Fil de Fer) é um projeto da escola 42 cujo objetivo é criar um programa capaz de exibir mapas tridimensionais em forma de wireframe (grade de linhas) em uma janela gráfica.

A proposta é transformar arquivos .fdf contendo uma malha de pontos 3D (com valores de altura) em uma representação visual em 2D, aplicando projeções matemáticas para simular uma visualização tridimensional.

O projeto desafia o aluno a trabalhar com manipulação de arquivos, algoritmos gráficos clássicos (como o de Bresenham), projeções 3D (como a isométrica) e o uso da MinilibX, uma pequena biblioteca gráfica fornecida pela 42

Um deleite para os amantes de matemarica e geometria espacial :D

# Projeção

   O que é uma projeção?
   Uma projeção é o processo matemático de representar um objeto tridimensional (3D) em uma superfície bidimensional (2D), como a tela do computador. Como a tela não tem profundidade real, precisamos simular a noção de profundidade e volume usando técnicas de projeção.
   
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
   
   Exemplos reais:
   
   Manual técnico de montagem: instruções da IKEA frequentemente usam isométrica.
   
   Mapas táticos ou sistemas de RPG de tabuleiro.

   Hades (estilizado, mas com base isométrica)
   
   SimCity 2000
   
   Diablo II
   
   RollerCoaster Tycoon
   

![jogo-Hades](https://www.numerama.com/wp-content/uploads/2021/08/73b6c0aa-d0a3-4cfb-b9cd-48a97525a186.jpg)

Jogo Hades

---

### 🔹 Projeção perspectiva

   Os “raios” convergem em um ponto de fuga. Objetos mais distantes parecem menores como vemos no mundo real. Isso cria uma sensação forte de profundidade.
   
   Exemplos reais:
   
   Fotografias reais
   
   Pinturas com perspectiva renascentista
   
   Cenas de filmes ou cinema
   
   The Legend of Zelda: Breath of the Wild
   
   Minecraft (modo de visão padrão)
   
   Qualquer jogo 3D em primeira ou terceira pessoa moderna, como Fortnite, GTA V, The Witcher 3

![csgo](https://i.pcmag.com/imagery/reviews/03aaBruU4YchhD6MkESCRns-6.fit_lim.size_925x520.v_1569469925.png)

Counter Striker Global Offensive
