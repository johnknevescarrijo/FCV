começando a ver os fundamentos.

- **2.1 Introdução:** O objetivo é projetar manualmente um sistema visual de ponta a ponta, inspirado no otimismo da década de 1960. Este capítulo foca especificamente na tarefa de **interpretação 3D** dentro de um cenário controlado.
- **2.2 Um Mundo Simples: O Mundo dos Blocos (Blocks World):** Para contornar a complexidade do mundo real, utiliza-se a estratégia de Larry Roberts (1963), limitando o ambiente a objetos geométricos simples com superfícies planas (horizontais ou verticais) repousando sobre um plano de fundo branco.
- **2.3 Um Modelo Simples de Formação de Imagem:** O sistema utiliza a **projeção paralela (ou ortográfica)**, em que os raios de luz viajam paralelos entre si e perpendiculares ao plano da câmera. Nesse modelo, o tamanho dos objetos não muda com a distância e linhas paralelas no mundo 3D permanecem paralelas na imagem 2D.
- **2.4 Um Objetivo Simples:** O foco principal deste exercício é **recuperar as coordenadas do mundo (X, Y, Z)** para cada pixel capturado pela câmera. Tarefas mais complexas, como determinar a cor real das superfícies compensando efeitos de iluminação, não são abordadas nesta etapa.

2.5 De Imagens para Bordas e Feições Úteis

Esta seção explica que uma imagem observada é uma função ℓ(x,y) que mapeia uma localização para uma intensidade de luz ou valor de cor. Embora o array de pixels seja uma representação razoável para a entrada inicial do processamento visual, ele não fornece informações diretas sobre a distância das superfícies. Para que o sistema consiga realizar a **interpretação 3D**, é necessário transformar a imagem em uma representação que torne explícitas as **fronteiras entre objetos** e as **mudanças na orientação das superfícies**. As imagens podem ser representadas inicialmente como coleções de pequenos fragmentos (_patches_), regiões de propriedades uniformes ou, como focado neste capítulo, **bordas (arestas)**.

2.5.1 Um Catálogo de Bordas

As bordas são definidas como regiões da imagem onde ocorrem mudanças acentuadas de intensidade em relação à localização. No sistema visual simplificado proposto, o primeiro passo é classificar essas bordas de acordo com a causa física mais provável na cena. O catálogo de bordas inclui:

- **Limites de Objeto:** Pixels que delineiam os contornos de qualquer objeto, geralmente marcados por mudanças de cor, textura ou orientação da superfície. Eles são subdivididos em:
    - **Bordas de contato:** Onde dois objetos estão em contato físico direto, portanto, sem descontinuidade de profundidade.
    - **Bordas de oclusão:** Onde um objeto está parcialmente à frente de outro ou do fundo, geralmente produzindo uma descontinuidade de profundidade.
- **Mudanças na Orientação da Superfície:** Locais onde a intensidade da imagem varia devido à mudança no ângulo entre a superfície e a luz incidente.
- **Bordas de Sombra:** Transições, muitas vezes suaves, entre regiões claras e escuras causadas pela iluminação.

Os autores observam que, apesar da aparente simplicidade desta tarefa no "Mundo dos Blocos", a classificação de bordas em cenas naturais é um problema **extremamente difícil** que exige a interpretação da cena em diversos níveis de complexidade.

2.5.2 -> ler essa.