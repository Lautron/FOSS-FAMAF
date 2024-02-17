#!/usr/bin/env python
# encoding: utf-8

"""
hget-test: bateria de test para cliente HTTP simple

Escrito con fines didacticos por la catedra de
Redes y Sistemas Distribuidos,
FaMAF-UNC

El proposito de este codigo es ejercitar el cliente hget para demostrar su
correcto funcionamiento; es decir, amplia aun mas los "doctest" incluidos
en la documentacion del cliente hget.
Prueba funciones auxiliares del cliente sin la necesidad de crear un
socket verdadero.
Revision 2019 (a Python 3): Pablo Ventura
Revision 2011: Eduardo Sanchez
Original 2010: Daniel Moisset

"""

import os
import unittest
import hget

TEMPFILE = 'test.tmp'


class FakeSocket(object):
    """
    Esta clase se comparta parecido a un socket, pero con datos en memoria.
    La usamos para testing, ya que es más simple construir una de estas que
    establecer una conexión real.
    """

    def __init__(self, data=()):
        self.sent = list(data)

    def sent_data(self):
        return (''.join(self.sent)).encode()

    def recv(self, count):
        result = ''.join(self.sent[:count])
        del self.sent[:count]
        return result.encode()

    def send(self, data):
        data = data.decode()
        self.sent += list(data)


class HgetTest(unittest.TestCase):

    def test_send_request(self):
        fake = FakeSocket('')
        hget.send_request(fake, 'abcde')
        self.assertEqual(fake.sent_data(), b'GET abcde HTTP/1.0\r\n\r\n')

    def test_read_line(self):
        fake = FakeSocket('text line\r\nother line\r\n')
        line = hget.read_line(fake)
        self.assertEqual(line, b'text line\r\n')
        line = hget.read_line(fake)
        self.assertEqual(line, b'other line\r\n')
        line = hget.read_line(fake)
        self.assertEqual(line, b'')

    def test_read_line_incomplete(self):
        fake = FakeSocket('text line')
        line = hget.read_line(fake)
        self.assertEqual(line, b'text line')

    def test_get_response(self):
        response = "HTTP/1.0 200 OK\r\n" \
                   "Encabezado: ignorado\r\n" \
                   "Otro: tambien deberia ser ignorado\r\n" \
                   "\r\n" \
                   "dato123456\n" \
                   "7890"
        hget.get_response(FakeSocket(response), TEMPFILE)
        f = open(TEMPFILE)
        self.assertEqual(f.read(), "dato123456\n7890")
        f.close()

    def tearDown(self):
        try:
            os.remove(TEMPFILE)
        except OSError:
            pass


if __name__ == "__main__":
    unittest.main()
