tests = [  {'description': 'add on press => PortC = 0x08',
    'steps': [ {'inputs': [('PINA',0x0E)], 'iterations': 5 },
	],
    'expected': [('PORTC',0x08)],
    },

    ]

watch['PORTB']
