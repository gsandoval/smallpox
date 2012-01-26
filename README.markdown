welcome to smallpox
===================

Motivation
----------
Writing distributed components is not always as easy as it sounds. First of all we face the problem of writing all those communication layer bits that doesn't add anything to the business and are pretty much the same for all projects.

So the main idea here is to provide a framework that allows the developer to have distribution enabled components out of the box. But not only enabled in the sense of that they can communicate using some socket/queue abstraction (sure, we can do that too), but in the sense that they don't need to worry even for writing code aware of replication, fail-over instances, etc.

There exist some frameworks which are already tested which might provide some kind of functionality that resembles what we propose, however there are two main things that this will give us that the other don't (AFAIK): 1) Full communication abstraction and already implemented distribution patterns and 2) the fun of implementing it myself.

Current State
-------------
I must warn you: don't expect much in the short term, this is something that I've been wanting to implement for a while now and it is not an easy task. I'm a human being and have a life when I get up of this chair/screen/keyboard.

With that said I'd be more than glad to have collaboration on this project, all you have to do is email me so we can coordinate.

smallpox is separated in two subprojects: moth and whitewhale. The first holds some low level abstractions for networking, threading, logging and common system access operations. The second (which still has not a single line of code in it) will contain the high level abstractions.
