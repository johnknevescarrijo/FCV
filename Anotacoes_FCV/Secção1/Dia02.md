2.5.2 Extraindo Bordas de Imagens

Esta secção descreve o procedimento técnico para identificar bordas, utilizando conceitos de **geometria diferencial**.

- **O Gradiente da Imagem:** A imagem é tratada como uma função contínua ℓ(x,y), e o grau de variação de intensidade é medido através do **gradiente**. A direção do gradiente aponta para onde a variação é maior, sendo perpendicular à borda.
- **Força e Orientação:** A **força da borda** é definida pela magnitude do gradiente, enquanto a **orientação da borda** é perpendicular à direção do gradiente.
- **Limiarização (Thresholding):** Para separar o que é borda do que são regiões uniformes (superfícies planas), o sistema aplica um limiar à força da borda. Pixels que superam esse valor são classificados como bordas, e sua orientação θ(x,y) é registrada para processamento posterior.

2.6 Das Bordas para as Superfícies

O objetivo central desta secção é **recuperar as coordenadas do mundo (X, Y, Z)** para cada localização de pixel (x,y) na imagem.

- **Simplicidade e Complexidade:** Recuperar a coordenada **X** é trivial, pois ela é observada diretamente na imagem (X=x). No entanto, recuperar **Y** (altura) e **Z** (profundidade) é difícil porque a projeção 2D mistura essas duas dimensões.
- **Segmentação Figura/Fundo:** O primeiro passo é separar os objetos do plano de fundo. No sistema simplificado, isso é feito pela cor: pixels brancos e pouco saturados são o chão, e o restante pertence aos blocos. Para o chão, define-se arbitrariamente Y=0.
- **Propriedades Não Acidentais:** O sistema assume que certas propriedades da imagem 2D refletem o mundo 3D de forma fiel (**Generic View**), como a **colinearidade** (linhas retas na imagem são retas no mundo) e a **suavidade** de curvas.
- **Propagação de Restrições:** Como a informação de orientação 3D só é clara nas bordas, o sistema utiliza o critério de que as faces dos objetos são **planas** para propagar essa informação das bordas para o interior das superfícies.
- **Inferência:** Todos esses requisitos (orientação das bordas, plano do chão, faces planas) são convertidos em um **sistema de equações lineares esparsas**, que pode ser resolvido eficientemente para encontrar a estrutura 3D completa da cena.


**2.6.1** trata da **Segmentação Figura/Fundo** (_Figure/Ground Segmentation_), que é o primeiro passo para transformar bordas em superfícies no sistema de visão simplificado apresentado no capítulo.

Aqui estão os pontos principais para entender essa seção:

- **Definição e Origem:** A segmentação de uma imagem em "figura" (o objeto de interesse) e "fundo" é um problema clássico da percepção humana e da visão computacional, introduzido originalmente pela **psicologia da Gestalt**. Um exemplo famoso desse desafio é a ilusão de ótica "dois rostos ou um vaso", onde o cérebro alterna entre o que considera ser a figura e o que considera ser o fundo.
- **Aplicação no "Mundo dos Blocos":** No sistema simplificado proposto pelos autores, essa tarefa é facilitada pelas propriedades do ambiente controlado. A decisão de qual pixel pertence ao objeto (figura) ou ao chão (fundo) é feita puramente através dos **valores de cor**:
    - **Fundo (Chão):** Pixels muito brilhantes e com **baixa saturação** (onde os valores de Vermelho, Verde e Azul são muito similares) são classificados como o plano de fundo branco.
    - **Figura (Objetos):** Os demais pixels, que possuem cores distintas e saturadas, são classificados como pertencentes aos blocos coloridos.
- **Consequência Geométrica:** Esta classificação é crucial para a reconstrução 3D porque permite aplicar restrições matemáticas imediatas. Se um pixel for identificado como "chão" e assumirmos que o chão é um plano horizontal, podemos definir arbitrariamente sua coordenada de altura no mundo como Y(x,y)=0.
- **Complexidade no Mundo Real:** Os autores ressaltam que, embora neste exemplo a segmentação seja trivial (baseada em cor), a segmentação de imagens em objetos distintos em cenários naturais continua sendo uma tarefa **extremamente desafiadora** para a visão computacional.

Em resumo, a seção 2.6.1 explica como o sistema separa o que é cenário (chão) do que é objeto, usando a cor para começar a "ancorar" as coordenadas tridimensionais da cena.

**2.6.2** foca nos **Bordas de Oclusão** (_Occlusion Edges_), que desempenham um papel fundamental na interpretação da profundidade de uma cena.

Os pontos principais desta seção são:

- **Definição:** Uma borda de oclusão é uma fronteira que separa duas superfícies diferentes situadas a **distâncias distintas** do observador.
- **Propriedade da Borda (Ownership):** Um conceito crucial introduzido é que, ao longo de uma borda de oclusão, um dos objetos está à frente do outro. Diz-se que o objeto que está na frente é o **"dono" da borda**.
- **Importância para a Geometria 3D:** Identificar qual superfície possui a borda é essencial porque as bordas fornecem pistas sobre a geometria tridimensional da cena. No entanto, essas pistas e restrições geométricas **aplicam-se apenas à superfície que detém a borda**, e não à superfície que está sendo obscurecida ao fundo.

Em resumo, para que o sistema de visão consiga reconstruir o mundo 3D corretamente, ele não precisa apenas detectar a borda, mas também decidir qual objeto está na frente para saber a qual deles aquela informação geométrica pertence.

**2.6.3** do livro aborda as **Bordas de Contato** (_Contact Edges_), que representam um tipo específico de transição entre objetos no sistema visual.

Aqui estão os pontos principais para entender esta seção:

- **Definição:** Bordas de contato são as fronteiras entre dois objetos distintos (ou entre um objeto e o chão) em locais onde **não existe descontinuidade de profundidade**. Isso ocorre quando os dois elementos estão se tocando fisicamente.
- **Oclusão sem Distância:** Apesar de não haver um "salto" na profundidade (como ocorre nas bordas de oclusão da seção anterior), os autores explicam que ainda existe uma forma de **oclusão**, pois uma superfície está escondida atrás ou sob a outra.
- **Propriedade da Borda (Ownership):** Assim como nas bordas de oclusão, o formato da borda de contato pertence a apenas **uma das duas superfícies**. Identificar qual objeto "detém" a borda é fundamental para que o sistema saiba qual geometria deve ser respeitada naquela coordenada.
- **Importância no Modelo:** No "Mundo dos Blocos", essas bordas são comuns na base dos objetos que repousam sobre o chão. Embora a cor mude, a profundidade no ponto de contato é a mesma para o objeto e para o solo.

Em resumo, enquanto a seção 2.6.2 tratava de objetos separados pelo espaço, a 2.6.3 trata de objetos que se tocam, onde o desafio é entender que, embora a profundidade seja contínua, a transição marca o fim de um objeto e o início de outro


**2.6.4** aborda a **Visão Genérica e Propriedades Não Acidentais da Cena** (_Generic View and Nonaccidental Scene Properties_), explicando como o sistema visual pode fazer suposições confiáveis sobre o mundo tridimensional a partir de uma imagem bidimensional.

Aqui estão os pontos fundamentais desta seção:

- **Propriedades Invariantes:** Embora a projeção de 3D para 2D perca muita informação, certas propriedades permanecem constantes e ajudam na interpretação da imagem. As principais mencionadas são:
    - **Colinearidade:** Uma linha reta no mundo 3D será projetada como uma linha reta na imagem.
    - **Coterminação:** Se várias linhas 3D terminam no mesmo ponto, suas projeções também terminarão em um ponto comum.
    - **Suavidade:** Uma curva suave em 3D projeta-se como uma curva suave em 2D.
- **A Suposição da Visão Genérica (****Generic View****):** O sistema assume que a imagem foi capturada de um ponto de vista "comum" e não de um ângulo "acidental". Um alinhamento acidental ocorreria se, por exemplo, um observador olhasse para um cubo de tal forma que uma linha horizontal parecesse perfeitamente vertical na imagem. O sistema ignora essas raras coincidências geométricas para facilitar a inferência.
- **Classificação na Prática:** No sistema simplificado do livro, utiliza-se o ângulo da borda em 2D para inferir sua orientação em 3D. Bordas que se desviam da verticalidade em mais de 15 graus são automaticamente rotuladas como horizontais no mundo 3D.
- **Tradução em Restrições:** Essas orientações inferidas (vertical ou horizontal) são convertidas em **restrições lineares** matemáticas. Essas restrições são formuladas em termos da coordenada de altura **Y(x, y)**, permitindo que o sistema calcule a estrutura tridimensional global da cena.

Em resumo, a seção 2.6.4 explica que o sistema visual confia que "o que parece ser, é", assumindo que as geometrias observadas na imagem (como retas e junções) refletem fielmente a estrutura física do objeto devido à improbabilidade de estarmos olhando de um ângulo acidental que distorça essas propriedades.


