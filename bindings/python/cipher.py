import math
import numpy as np
from numpy.polynomial import polynomial as poly

from . import encoder

CKKSPair = tuple[np.array, np.array]

def nearest_pow2(n: int):
    l = math.log2(n)
    return (2 ** round(l)) if l != int(l) else n
#Should be private as cannot encode
class CKKSCipherText:

    def __init__(self, cipher: CKKSPair):
        self.cipher = cipher

        #Should make immutable properties
        self.fst = self.cipher[0]
        self.snd = self.cipher[1]

    def add_plain(self, encoded_val: np.array) -> None:
        self.fst = poly.polyadd(encoded_val, self.fst)

    def mul_plain(self, encoded_val: np.array, scale: float) -> None:
        self.fst = (1/scale) * poly.polymul(encoded_val, self.fst)
        self.snd = (1/scale) * poly.polymul(encoded_val, self.snd)



class CKKSKeys:
    
    def __init__(self, n: int, q: int, scale: float = 32768): # 2 ^ 15
        rng = np.random.default_rng()
        self.n = nearest_pow2(n)
        self.q = q
        self.scale = scale
        
        self.a = rng.integers(-self.q, self.q, size=self.n, endpoint=True) 
        
        secret_scale = self.q - round(math.log2(self.q))
        self.s = rng.integers(-secret_scale, secret_scale,
                size=self.n, endpoint=True)

        #Do normal nexttime
        self.e = rng.integers(-1, 1, size=self.n, endpoint=True)
        self.public_key = (poly.polyadd #Why do i have to split like this?
                (poly.polymul(-self.a, self.s), self.e),
                self.a)

        self.encoder = encoder.CKKSEncoder(self.n * 2, self.scale)


    def encrypt(self, msg: np.array) -> CKKSCipherText:
        encoded_msg = self.encoder.encode(msg)
        return CKKSCipherText((poly.polyadd(encoded_msg, self.public_key[0]), 
                self.public_key[1]))

    def decrypt(self, encryted_msg: CKKSCipherText,
            round_scale: int = None, isReal: bool = False) -> np.array:

        decrypted_encoded_msg = poly.polyadd(
                encryted_msg.fst, poly.polymul(encryted_msg.snd, self.s))

        decoded =  self.encoder.decode(decrypted_encoded_msg)
        
        if isReal:
            decoded = np.real(decoded)

        if round_scale is not None:
            decoded = np.round(decoded, round_scale)

        return decoded


    def add_plain(self, cipher: CKKSCipherText, val: np.array) -> None:
        cipher.add_plain(self.encoder.encode(val))

    def mul_plain(self, cipher: CKKSCipherText, val: np.array) -> None:
        cipher.mul_plain(self.encoder.encode(val), self.scale) 


