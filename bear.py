import time

class Bear:
    def __init__(self):
        self.is_hungry = False
        self.is_alive = True
        self.SLEEP_TIME = 3
        self.NORM_EATING = 50

    def eat_of_honey(self, honey, lock):
        while (self.is_alive):
            time.sleep(self.SLEEP_TIME)
            lock.acquire()
            try:
                if self.is_hungry and honey.count < self.NORM_EATING:
                    self.is_alive = False
                    print("Медведь скончался от нехватки меда((")

                elif not self.is_hungry and honey.count < self.NORM_EATING:
                    self.is_hungry = True
                    print("Медведь остался голодным(( Меда осталось:", honey.count)
                    
                else:
                    self.is_hungry = False
                    honey.count -= self.NORM_EATING
                    print("Медведь съел мед. Осталось:", honey.count)
                
            finally:
                lock.release()
        