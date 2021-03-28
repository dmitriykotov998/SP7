from threading import Thread, RLock, get_ident
import time

from bee import*
from bear import*

class Honey:
    def __init__(self, count):
        self.count = count


if __name__ == "__main__":
    AMOUNT_OF_HONEY = 40
    NUMBER_OF_BEES = 3

    honey = Honey(AMOUNT_OF_HONEY)
    bees = []
    for i in range(NUMBER_OF_BEES):
        bees.append(Bee(i))
    bear = Bear()

    lock = RLock()
    
    bees_threads = []
    for i in range(NUMBER_OF_BEES):
        bees_threads.append(Thread(target=bees[i].bring_honey,args=(honey, lock, True), daemon=True))
        bees_threads[i].start()

    bear_thread = Thread(target=bear.eat_of_honey, args=(honey, lock))
    bear_thread.start()


            
