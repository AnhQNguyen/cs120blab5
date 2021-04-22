tests = [  {'description': 'PINA: 0xF8 => PORTC: 0x3C',
    'steps': [ {'inputs': [('PINA',0xF8)], 'iterations': 5 } ],
    'expected': [('PORTC',0x3C)],
    },
    {'description': 'PINA: 0xFF => PORTC: 0x40',
    'steps': [ {'inputs': [('PINA',0xFF)], 'iterations': 5 } ],
    'expected': [('PORTC',0x40)],
    },
    {'description': 'PINA: 0x7C => PORTC: 0x70',
    'steps': [ {'inputs': [('PINA',0x7C)], 'iterations': 5 } ],
    'expected': [('PORTC',0x70)],
    },
    ]
watch = ['PORTC']
