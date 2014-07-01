# -*- coding: utf-8 -*-
"""
Created on Mon Jun 23 15:56:41 2014

@author: Gonçalo Martins
"""

from __future__ import print_function
from __future__ import division
from collections import deque
import time

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
            for prime, value in self.iterators.iteritems():
                if current == value:
                    self.iterators[prime] += prime
                    is_prime = False
            if(len(self.in_buffer) == 1):
                self.generateInput()
                
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

    # Returns the next prime
    def getPrime(self):
        if(self.index) >= (len(self.primes)):
            self.index += 1            
            return self.generatePrime()
        else:
            self.index += 1
            return self.primes[self.index-1]

    def resetPrime(self):
        self.index = 0

    # Returns whether the given value is a prime number
    def isPrime(self, n):
        if(len(self.primes) == 0):
            self.generatePrime()
        while(self.primes[-1] < n):
            self.generatePrime()
        if(n in self.iterators):
            return True
        else:
            return False

    # Constructor
    def __init__(self):
        # Initialize stuff
        self.index = 0
        self.in_buffer = deque(range(2,101))
        self.primes = []
        self.wheel = []
        self.iterators = {prime: prime*prime for prime in self.primes}


# Calculates the product of a list
def product(list):
    p = 1
    for i in list:
        p *= i
    return p

# Determines the number of divisors via prime number factorization
def numDivisors(n):#, sieve):
    #sieve.resetPrime
    sieve = SieveOfErastothenes()
    composite = n
    exponents = [0]
    current_prime = sieve.getPrime()
    ever_divided = False
    while(composite != 1):
        if composite % current_prime == 0:
            composite /= current_prime
            exponents[-1] += 1
            ever_divided = True
        else:
            if ever_divided == True:
                exponents[-1] += 1
                exponents.append(0)
                ever_divided = False
            current_prime = sieve.getPrime()
    exponents[-1] += 1
    return product(exponents)


# Gets our answer
def loop():
    i = 1
    current_number = 0
    num = 0
    current_max = 0
    while(num < 500):
        current_number += i
        i += 1
        num = numDivisors(current_number)
        if num > current_max:
            current_max = num
        #print(current_number, num, current_max)
    print("I think I've found something: " + str(current_number))
    
sieve = SieveOfErastothenes()
start = time.time()
loop()
elapsed = (time.time() - start)
print("We took {} seconds to compute an answer.".format(elapsed))
#for i in xrange(1,10):
#    print(i,numDivisors(i))
