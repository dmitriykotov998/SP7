import random
import time

class Bee:
    def __init__(self, id):
        self.CAPACITY = 2
        self.MIN_TIME = 1
        self.MAX_TIME = 3
        self.id = id

    def bring_honey(self, honey, lock, run):
        while run:
            time_sleep = random.random() * (self.MAX_TIME - self.MIN_TIME) + self.MIN_TIME
            time.sleep(time_sleep)

            lock.acquire()
            try:
                honey.count += self.CAPACITY
                print("Пчела", self.id, "принесла мед. Кол-во меда:", honey.count)
            finally:
                lock.release()
