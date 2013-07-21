{
  'targets': [{
    'target_name': 'qagamei386',
    'type': 'shared_library',
    'msvs_guid': '905C1895-E657-4584-B1C9-C8642BDA8523',
    'dependencies': [

    ],
    'defines': [
      'DEFINE_FOO',
      'DEFINE_A_VALUE=value',
    ],
    'include_dirs': [

    ],
    'sources': [
      'client/recordsystem.cc',
      'client/recordsystem.h',
    ],
    'conditions': [
      ['OS=="linux"', {
        'defines': [
          'LINUX',
        ],
        'include_dirs': [

        ],
      }],
      ['OS=="win"', {
        'defines': [
          'WIN32',
        ],
        'include_dirs': [

        ],
      }],
    ],
  }],
}
