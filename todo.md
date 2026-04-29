*** PROJETO CUB3D Versão 0.4 ***
_atualizado: 29/04/2026 por: bmoreira_

Divisão do projeto:

*** PARSER ***

- [  ] obter caminho das texturas (NO, SO, WE, EA)
- [  ] obter cor do chão e teto
- [  ] obter grid do mapa
- [  ] obter posição inicial do player
- [  ] obter orientação de spawn do player (não precisa)

*** VALIDATOR ***

- [  ] validar extensão do mapa (.cub)
- [  ] validar caracteres possíveis do grid do mapa (0, 1, N, S, E, W)
- [  ] validar paredes do mapa
- [  ] validar caminho das texturas (identificador-espaço-path)
- [  ] validar cores (identificador-espaço-rgb)
- [  ] validar separação dos elementos (uma ou mais linhas vazias)
- [  ] validar posição do grid (por último no arquivo)

*** RENDER ***

- [✅] renderizar formas básicas (linhas, retângulos, etc)
- [✅] renderizar o mapa 2D
- [✅] renderizar o player
- [✅] implementar a estrutura do 9-point para o raycasting
- [  ] renderizar o raycasting
- [✅] organizar os layers de buffers
- [✅] renderizar sprites
- [✅] renderizar texturas
- [✅] renderizar minimapa
- [✅] renderizar offset do minimapa

*** INPUT ***

- [✅] implementar detecção de teclas (setas, etc)
- [  ] implementar movimentação do player
- [  ] implementar movimentação da câmera
- [  ] implementar interação com o ambiente (portas, etc)