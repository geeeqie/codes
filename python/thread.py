#!/usr/bin/python2
import threading
import Queue
import time

queue = Queue.Queue()

class DispatchThread(threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self)
    def run(self):
        while True:
            s = queue.get()
            print "thread:" + s
            time.sleep(1)
            queue.task_done()
        
t = DispatchThread()
t.setDaemon(True)
t.start()

while True:
    print "::",
    queue.put(raw_input())
print "END"

