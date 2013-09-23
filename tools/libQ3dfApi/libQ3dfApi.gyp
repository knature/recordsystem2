{
	'make_global_settings': [
		['CXX','/usr/bin/g++'],
 		['LINK','/usr/bin/g++'],
	],
	'targets': [{
		'target_name': 'Q3dfApi',
		'type': 'static_library',
		'msvs_guid': 'EEE489A6-F54C-4A20-945F-326EAB9654E0',
		'dependencies': [
		],
		'defines': [
		],
		'include_dirs': [
			'../protorpc/src/'
		],
		'actions': [{
			'action_name': 'protoc echoService compiling',
			'inputs': [
				'echoservice.proto'
			],
			'outputs': [
				'echoservice.pb.cc',
				'echoservice.pb.h',
			],
			'action': [
				'../../compileprotoc.sh',
				'./',
				'echoservice.proto'
			],
		}],
		'sources': [
			'echoservice.pb.cc',
			'echoservice.pb.h',
		],
		'conditions': [
			['OS=="linux"', {
				'defines': [
					'LINUX',
				],
				'include_dirs': [
				],
				'link_settings': {
					'libraries': [
						'../protorpc/lib/libprotobuf-posix32.a',
						'-pthread'
					],
					'library_dirs': [
					]
				},
			}],
			['OS=="win"', {
				'defines': [
					'WIN32',
				],
				'msvs_settings': {
					'VCLinkerTool': {
						'AdditionalDependencies': [
							'../protorpc/lib/protobuf-win32.lib'
						],
					},
				},
				'include_dirs': [
				],
			}],
		],
	}],
}