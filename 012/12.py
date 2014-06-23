# -*- coding: utf-8 -*-
"""
Created on Mon Jun 23 15:56:41 2014

AINDA EXISTE UM ERRO, VER CADERNO

@author: Gonçalo Martins
"""

from __future__ import print_function
from __future__ import division
from collections import deque

# Class that implements the Sieve of Erastothenes
# Implements the incremental algorithm described in "The Genuine Sieve of
# Erasthotenes", by M. E. O'Neill.
class SieveOfErastothenes:
    # Returns the next prime
    def generatePrime(self):
        is_prime = False
        current = 0

        while(is_prime == False):
            is_prime = True
            current = self.in_buffer.popleft()
            print(current)
            for prime, value in self.iterators.iteritems():
                if current == value:
                    self.iterators[prime] += prime
                    is_prime = False
            if(len(self.in_buffer) == 1):
                self.generateInput()
                is_prime = False
                
        self.primes.append(current)
        self.iterators[current] = current*current
        return current
    
    # Returns all primes we have so far
    def getPrimes(self):
        return self.primes
    
    # Returns our iterators dictionary
    def getIterators(self):
        return self.iterators

    # Returns our input buffer
    def getInput(self):
        return self.in_buffer

    # Adds elements to the input buffer
    def generateInput(self):
        # Populate the input buffer
        last = self.in_buffer.popleft()
        self.in_buffer.extend(range(last, last+101))
        print("Last value was " + str(last) + ".")
        print("Inputting values from " + str(last) + " to " + str(last+100))

    # Constructor
    def __init__(self):
        # Initialize stuff
        #self.starter_primes = [2, 3, 5, 7]
        self.in_buffer = deque(range(2,101))
        self.primes = []
        self.wheel = []
        self.iterators = {prime: prime*prime for prime in self.primes}


#def numDivisors(n):



def loop():
    i = 1
    current_number = 0
    num = 0
    while(num < 500):
        current_number += i
        i += 1
        num = numDivisors(current_number)
        print(str(num))
    print("I think I found something: " + str(num))
    
sieve = SieveOfErastothenes()

for i in range(50):
    sieve.generatePrime()
    #print(sieve.getIterators())
    
unique = set(sieve.getPrimes())
print(sieve.getPrimes())
print(len(unique))