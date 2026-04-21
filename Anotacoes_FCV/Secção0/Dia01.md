Introdução ao Livro Fundations Computer Vision.

1
O objetivo de um cientista da visão é duplo: entender como a percepção funciona e construir sistemas que possam interpretar o mundo ao seu redor usando imagens (ou sequências de imagens) como entrada. Neste capítulo, queremos fornecer uma perspectiva ampla sobre a ciência da visão e as múltiplas disciplinas que contribuem para ela.

1.2
David Marr [317] define visão como "saber o que está onde, olhando", e acrescenta: "a visão é o processo de descobrir, a partir de imagens, o que está presente no mundo e onde está".

É difícil dizer exatamente o que torna a compreensão dos mecanismos da visão algo complexo, pois ainda não temos uma solução completa [71]. Nesta seção, mencionaremos dois aspectos que tornam a visão desafiadora: a estrutura da entrada (input) e a estrutura da saída desejada (output).

1.2.2
O objetivo da visão é fornecer ao observador informações relevantes para a compreensão do mundo exterior e permitir-lhe resolver outras tarefas, como navegar pelo mundo, interagir com outros agentes e encontrar comida. As tarefas em visão computacional incluem o seguinte: detectar mudanças no ambiente; estimativa de movimento; reconhecimento e localização de objetos; reconhecimento de materiais; leitura de texto e símbolos visuais; construção de modelos 3D a partir de imagens; encontrar espaço livre para se mover; encontrar outras pessoas; decidir se a comida está em bom estado; e compreender o comportamento de animais. Nem todas essas tarefas estão no mesmo nível. Algumas parecem exigir muito conhecimento externo, enquanto outras parecem solucionáveis apenas a partir das imagens.

**1.3 Teorias da Visão**

Nesta seção, queremos descrever, com algumas pinceladas, algumas das teorias da visão que contribuíram para e moldaram as abordagens modernas. Pense nesta seção como um folheto de viagem que lhe mostrará alguns instantâneos de uma jornada, mas que não pretende ser um substituto para viajar você mesmo. Você deve ler os livros e artigos que mencionaremos nesta seção, pois eles são os alicerces sobre os quais este campo fascinante foi construído.


