import threading
import time
import random
from collections import deque

BUFFER_SIZE = 10

# Shared resources
buffer = deque(maxlen=BUFFER_SIZE)
mutex = threading.Semaphore(1)
empty = threading.Semaphore(BUFFER_SIZE)
full = threading.Semaphore(0)

class Producer(threading.Thread):
    def run(self):
        while True:
            item = random.randint(1, 100)
            empty.acquire()
            mutex.acquire()
            buffer.append(item)
            print(f"Produced {item} | Buffer: {list(buffer)}")
            mutex.release()
            full.release()
            time.sleep(random.random())

class Consumer(threading.Thread):
    def run(self):
        while True:
            full.acquire()
            mutex.acquire()
            item = buffer.popleft()
            print(f"Consumed {item} | Buffer: {list(buffer)}")
            mutex.release()
            empty.release()
            time.sleep(random.random())

# Create threads
producer = Producer()
consumer = Consumer()

# Start threads
producer.start()
consumer.start()

# Wait for keyboard interrupt
try:
    while True:
        time.sleep(1)
except KeyboardInterrupt:
    print("\nStopping...")
    producer.join()
    consumer.join()