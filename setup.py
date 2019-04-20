from distutils.core import setup, Extension


beenode_hash_module = Extension('beenode_hash',
                               sources = ['beenodemodule.c',
                                          'beenode.c',
										  'honeycomb/facet_one.c',
										  'honeycomb/facet_two.c',
										  'honeycomb/facet_three.c',
										  'honeycomb/facet_four.c',
										  'honeycomb/facet_five.c',
										  'honeycomb/facet_six.c'],
                               include_dirs=['.', './honeycomb'])

setup (name = 'hashs',
       version = '1.0',
       description = 'Binding for Beenode Honeycomb proof of work hashing.',
       ext_modules = [beenode_hash_module])
