**2.6.5** trata da **Propagação de Restrições** (_Constraint Propagation_), explicando como o sistema preenche as "lacunas" de informação entre as bordas de um objeto.

Aqui estão os pontos principais desta seção:

- **O Problema das Regiões Vazias:** As bordas fornecem informações valiosas sobre a estrutura 3D, mas a maior parte de uma imagem é composta por regiões "vazias" ou uniformes (como o interior da face de um bloco). Nessas áreas, não existem pistas locais suficientes para inferir a orientação da superfície.
- **Necessidade de Propagação:** Para reconstruir o objeto por completo, o sistema precisa de critérios para propagar (espalhar) a informação geométrica obtida nas bordas para o interior dessas regiões planas.
- **A Suposição de Planaridade:** No sistema simplificado do livro, assume-se que as faces dos objetos são **planas**. Essa suposição é a chave para a propagação: se sabemos como as bordas se comportam e sabemos que a superfície entre elas não dobra, podemos deduzir a geometria de toda a face.
- **Formulação Matemática:** Essa restrição de planaridade é imposta definindo que a **derivada de segunda ordem** da coordenada de altura (**Y**) deve ser zero. Na prática computacional, isso é aproximado por uma equação linear que relaciona o valor de um pixel com seus vizinhos imediatos (ex: 2Y(x,y)−Y(x+1,y)−Y(x−1,y)≃0).

Em resumo, a seção 2.6.5 mostra que, ao assumir que as superfícies são retas e planas, o sistema consegue "adivinhar" o que acontece no meio de um objeto apenas olhando para os seus contornos.

**2.6.6** descreve o **Esquema de Inferência Simples** (_A Simple Inference Scheme_), que é o estágio final onde todas as restrições geométricas discutidas anteriormente são combinadas para reconstruir a cena.

Aqui estão os pontos fundamentais para entender como o sistema realiza esse cálculo:

- **Sistema de Equações Lineares:** Todas as pistas coletadas — como a altura zero do chão, as orientações das bordas (verticais ou horizontais) e a planaridade das faces — são convertidas em um grande **sistema de equações lineares sobre-determinado**. Isso significa que há muito mais equações do que pixels na imagem, o que ajuda a encontrar uma solução robusta.
- **Vetorização:** Para facilitar a matemática, a imagem Y(x,y) (que representa a altura de cada ponto) é tratada como um **vetor plano**, onde todas as linhas de pixels são empilhadas uma após a outra.
- **Minimização do Erro:** Como nem sempre é possível satisfazer todas as restrições perfeitamente (especialmente em imagens com ruído ou ambiguidades), o sistema busca a solução que **minimiza uma função de custo** baseada no erro quadrático (J=∑(ai​Y−bi​)2).
- **Uso de Pesos:** Se algumas restrições forem consideradas mais confiáveis que outras (por exemplo, a planaridade do chão vs. a orientação de uma borda pequena), o sistema permite adicionar **pesos (**wi​**)** para dar mais importância a certas equações.
- **Solução Matemática:** A solução final para a estrutura tridimensional é calculada utilizando a **pseudoinversa** da matriz de restrições.
- **Eficiência Computacional:** Embora o sistema de equações seja enorme, a matriz resultante é **muito esparsa** (a maioria dos seus valores é zero), o que permite que computadores resolvam o problema de forma extremamente rápida e eficiente.

Em resumo, a seção 2.6.6 explica como o sistema "fecha a conta", transformando observações visuais isoladas em um modelo matemático sólido que revela as coordenadas X,Y e Z de cada pixel, resultando na reconstrução 3D completa da cena.


**2.6.7** apresenta os **Resultados** (_Results_) finais obtidos pelo sistema de visão simplificado, demonstrando o que foi possível reconstruir a partir das etapas anteriores.

Aqui estão os pontos fundamentais desta seção:

- **Visualização das Coordenadas:** O sistema gera três imagens que representam as coordenadas do mundo recuperadas: **X** (posição horizontal), **Y** (altura) e **Z** (profundidade). Nessas visualizações, o nível de cinza indica o valor de cada coordenada, permitindo "ver" como o computador interpretou a posição espacial de cada pixel.
- **Eficácia no Mundo dos Blocos:** Os autores destacam que o algoritmo funciona de forma satisfatória para o cenário proposto, sendo capaz de realizar a interpretação 3D com sucesso dentro dos limites do ambiente controlado.
- **Re-renderização em 3D:** Para validar o resultado, a estrutura 3D inferida é renderizada novamente a partir de **diferentes pontos de vista**. Isso demonstra que o sistema não apenas "etiquetou" a imagem, mas criou um modelo volumétrico coerente que pode ser observado de outros ângulos.
- **Reflexões Críticas e Limitações:**
    - **Dependência de Suposições:** O sucesso do sistema deve-se às diversas suposições feitas (chão horizontal, superfícies planas, projeção paralela), que dificilmente seriam mantidas em imagens do mundo real.
    - **Necessidade de Avaliação:** Os autores mencionam a importância de estabelecer métricas para avaliar o quão bem o sistema funciona, além da simples inspeção visual.
    - **Ponto de Partida:** Esta seção encerra a demonstração do sistema "artesanal", servindo de base para o restante do livro, que focará em como atualizar essas abordagens para processar imagens gerais e complexas.

Em resumo, a seção 2.6.7 mostra que, embora as ferramentas matemáticas básicas (como álgebra linear e geometria diferencial) permitam reconstruir o mundo, a visão computacional moderna precisa ir além de regras manuais para lidar com a imprevisibilidade da realidade.

**2.7** aborda a **Generalização** (_Generalization_), um conceito fundamental para qualquer sistema de visão artificial.

Aqui estão os pontos principais desta seção:

- **Definição:** A generalização é a capacidade de um sistema operar corretamente fora do domínio específico para o qual foi projetado.
- **Domínio no Sistema Manual vs. Aprendizado:** No sistema "artesanal" construído neste capítulo, o domínio é definido pelas suposições manuais feitas (como o Mundo dos Blocos e superfícies planas). Em sistemas baseados em **Deep Learning** (vistos mais adiante no livro), o domínio é definido pelo **conjunto de dados de treinamento**.
- **Teste de Estresse:** Os autores testam o algoritmo com imagens que violam as suposições iniciais:
    - Uso de sombras que não são "suaves".
    - Configurações não planejadas, como um objeto empilhado sobre o outro (um cubo verde sobre um bloco vermelho).
- **Observações dos Resultados:** Surpreendentemente, o sistema consegue produzir resultados razoáveis mesmo nessas condições adversas, mas os autores alertam que isso é instável e que o processo "poderia ter dado errado" facilmente, pois o modelo não foi projetado para essas complexidades.
- **Figuras Impossíveis:** A seção também mostra o sistema tentando reconstruir figuras "impossíveis" (como a ilusão dos degraus de Adelson). O algoritmo tenta aproximar as restrições matemáticas da melhor forma possível, e a reconstrução resultante acaba concordando com a nossa própria percepção visual 3D humana.

Em resumo, a seção 2.7 serve como um lembrete de que sistemas baseados em regras rígidas são limitados pelo seu "mundo" de suposições, e que o verdadeiro desafio da visão computacional é criar modelos que se adaptem à imprevisibilidade do mundo real.


**2.8** apresenta as **Observações Finais** (_Concluding Remarks_) do Capítulo 2, servindo como uma reflexão crítica sobre o sistema de visão artesanal que foi construído.

Aqui estão os pontos principais desta conclusão:

- **Falta de Representação de Objetos:** Apesar de o sistema conseguir gerar uma representação 3D das coordenadas da cena, ele ainda não tem "consciência" de que a cena é composta por **objetos distintos**. Ele vê apenas uma superfície contínua de pontos e não entende, por exemplo, o conceito individual de um "bloco".
- **Limitações Funcionais:** Devido a essa falta de representação de objetos, o sistema é incapaz de realizar tarefas simples para humanos, como **contar quantos cubos** existem na imagem. Além disso, ele não consegue prever ou visualizar as **partes ocluídas** (escondidas) dos objetos.
- **Potencial de Re-renderização:** Os autores sugerem que uma representação detalhada do mundo permitiria renderizar a imagem de volta para verificar se a compreensão está correta. Isso permitiria ao sistema fazer **predições verificáveis**, como inferir o que seria visto ao olhar por trás de um objeto.
- **Integração de Conhecimentos:** O capítulo conclui reforçando que, para chegar a esses resultados, foi necessário unir conceitos de visão com ferramentas matemáticas de **álgebra e cálculo**.
- **Próximos Passos:** A conclusão serve de ponte para o restante do livro, indicando que fechar o ciclo entre a interpretação da cena e o input original será fundamental para sistemas de visão mais robustos.

Em resumo, a seção 2.8 reconhece que, embora o modelo matemático funcione para reconstruir a geometria, ele ainda carece da "inteligência" necessária para segmentar e entender o mundo como um conjunto de entidades individuais.