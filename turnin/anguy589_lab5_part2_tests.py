  
tests = [  {'description': 'PINA: 0x00 => PORTC: 0x07',
    'steps': [ {'inputs': [('PINA',0x00)], 'iterations': 5 } ],
    'expected': [('PORTC',0x07)],
    },
    {'description': 'PINA: 0x01 => PORTC: 0x08',
    'steps': [ {'inputs': [('PINA',0x01)], 'iterations': 5 } ],
    'expected': [('PORTC',0x08)],
    },
    {'description': 'PINA: 0x02 => PORTC: 0x07',
    'steps': [ {'inputs': [('PINA',0x02)], 'iterations': 5 } ],
    'expected': [('PORTC',0x07)],
    },
    ]
watch = ['PORTC']
