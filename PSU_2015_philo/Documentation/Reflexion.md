# Philosophes - Kick-Off #

- problème très connu -> différents programmes s'exécutent en même temps ==> Diner des philosophes sur Wiki
- quand un thread prend une ressource un autre ne peut pas prendre la même -> des mutexs
- un interblocage : quand un thread A prend une ressource, le B sera bloqué MAIS quand un thread A prend la ressource 1 et le B prend la ressource 2; les 2 ont besoin des deux ressources, et donc il y a un interblocage car les deux vont attendre que l'autre libère la ressource ce qui ne se fera jamais

==> THREAD/MUTEXS sont utilisés partout par tout les OS !! C'est super important et ça permet d'utiliser vraiment nos ressours de processeurs.


# Sujet #

## Généralités ##

- N philosophes assis à une table
- Chaque philosophe a un bol de riz en face de lui
- Une baguette à gauche de chaque bol
- Un philosophe peut prendre une baguette si elle est à gauche ou à droite de son bol seulement
- Le philosophe a 3 états : MANGER (avec deux baguettes, gauche/droite), DORMIR (n'utilise pas de baguette) et PENSER (utilise une baguette)

## Règles ##

- un philosophe qui PENSE doit MANGER avant de DORMIR
- après avoir DORMI, il peut PENSER/MANGER
- PENSER et MANGER ont des durées maximales qu'on doit définir
- une baguette ne peut pas être utilisée par deux philosophes en même temps

## Détails techniques ##

Il faut créer un simulateur.

Le programme prend 4 paramètres :

- `-p` suivit du nombre de philosophes
- `-e` suivit du nombre de fois qu'un philosophe peut manger
