7 Cameras as Linear Systems

**7.1 Introdução (Introduction)**

Esta seção introduz uma mudança fundamental na forma de pensar sobre câmeras, movendo-se da geometria física simples para a modelagem matemática de sistemas lineares.

- **Limitação dos Modelos Tradicionais:** Câmeras baseadas em lentes e pinholes são casos especiais onde a luz forma uma imagem diretamente interpretável no sensor.
- **Sistemas Não Convencionais:** Em outras áreas, como na **medicina ou astronomia**, as intensidades registradas por um sensor podem não se parecer em nada com uma imagem visual à primeira vista.
- **A Câmera como Matriz:** Como os componentes óticos geralmente respondem de forma **linear** à luz, é conveniente e poderoso descrever o processo de captura usando **álgebra linear**.
- **Poder de Reconstrução:** Essa formulação matemática oferece o maquinário necessário para recuperar uma imagem nítida a partir de dados registrados que inicialmente parecem confusos ou codificados.
- **Inovação no Design:** Além de ajudar na compreensão de sistemas existentes, pensar em câmeras como sistemas lineares permite a criação e o design de **novos tipos de câmeras** computacionais.

Em resumo, a seção 7.1 estabelece que tratar o processo de imageamento como uma operação linear permite aplicar ferramentas matemáticas avançadas para extrair informações visuais de quase qualquer sistema que capture luz.

**7.2 Flatland**

Esta seção introduz o conceito de "Flatland" (Mundo Plano) para simplificar a visualização e a compreensão de sistemas de imagem através da redução da dimensionalidade.

- **Simplificação para 1D:** Para facilitar a visualização, os autores propõem considerar sistemas de imagem unidimensionais (1D), onde tanto o sensor quanto a cena existem em um plano bidimensional simplificado.
- **Vetor de Intensidades (**ℓw​**):** As intensidades de luz no mundo são representadas por um vetor coluna ℓw​. Cada componente n desse vetor fornece a intensidade da luz em uma posição específica, movendo-se na direção da câmera.
- **Convenção de Coordenadas:** Seguindo a lógica da câmera pinhole, o eixo no sensor da câmera é invertido, e as unidades de medida são pixels.
- **Modelo de Cena:** A cena é modelada como uma linha com diferentes albedos (refletâncias) situada a uma profundidade fixa em relação à câmera. Estruturas espaciais mais complexas exigiriam o uso de "campos de luz" (_light fields_), abordados mais adiante no livro.
- **Aproximação por Raios Discretos:** Para permitir o uso de álgebra linear na descrição do processo de captura, a luz de entrada é aproximada por um conjunto discreto e finito de raios de luz, em vez de ser tratada como uma onda contínua.

