tests = [ {'description': 'PINA: 0x01 => PORTC: 0x08, state: c_plus',
    'steps': [{'inputs': [('PINA', 0x01)], 'iterations': 2}],
    'expected': [('PORTC',0x08)],
    },

    {'description': 'PINA: 0x02 => PORTC: 0x06, state: c_minus',
        'steps': [{'inputs': [('PINA', 0x02)], 'iterations': 2}],
        'expected': [('PORTC',0x06)],
        },

    {'description': 'PINA: 0x03 => PORTC: 0x00, state: c_reset',
        'steps': [{'inputs': [('PINA', 0x03)], 'iterations': 2}],
        'expected': [('PORTC',0x00)],
      },
  ]

#watch = ['c_state']
