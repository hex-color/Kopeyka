// Copyright (c) 2011-2016 The Cryptonote developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <cstdint>
#include <initializer_list>

namespace CryptoNote {
namespace parameters {

const uint64_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 500000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;
//TODO Currency-specific address prefix
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 0x2;
//TODO Choose maturity period for your currency
const size_t   CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 60;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = 60 * 60 * 2;

const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 60;

//TODO Specify total number of available coins
//TODO ((uint64_t)(-1)) equals to 18446744073709551616 coins
//TODO or you can define number explicitly UINT64_C(858986905600000000)
const uint64_t MONEY_SUPPLY                                  = ((uint64_t)(-1));
const unsigned EMISSION_SPEED_FACTOR                         = 18;
static_assert(EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");

//TODO Define number of blocks for block size median calculation
const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     = 20000; //size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;
//TODO Define number of digits
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 8;
//TODO Define minimum fee for transactions
const uint64_t MINIMUM_FEE                                   = 100000;
const uint64_t DEFAULT_DUST_THRESHOLD                        = MINIMUM_FEE;

//TODO Define preferred block's target time
const uint64_t DIFFICULTY_TARGET                             = 120; // seconds
const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;
//TODO There are options to tune CryptoNote's difficulty retargeting function.
//TODO We recommend not to change it.
const size_t   DIFFICULTY_WINDOW                             = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; // blocks
const size_t   DIFFICULTY_CUT                                = 60;  // timestamps to cut after sorting
const size_t   DIFFICULTY_LAG                                = 15;
static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

const size_t   MAX_BLOCK_SIZE_INITIAL                        =  20 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = 60 * 60 * 24;     //seconds, one day
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = 60 * 60 * 24 * 7; //seconds, one week
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

const size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 30 / 100;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

const char     CRYPTONOTE_BLOCKS_FILENAME[]                  = "blocks.dat";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            = "blockindexes.dat";
const char     CRYPTONOTE_BLOCKSCACHE_FILENAME[]             = "blockscache.dat";
const char     CRYPTONOTE_POOLDATA_FILENAME[]                = "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]                       = "p2pstate.bin";
const char     CRYPTONOTE_BLOCKCHAIN_INDICES_FILENAME[]      = "blockchainindices.dat";
const char     MINER_CONFIG_FILE_NAME[]                      = "miner_conf.json";
} // parameters

//TODO Put here the name of your currency
const char     CRYPTONOTE_NAME[]                             = "Kopeyka";
const char     GENESIS_COINBASE_TX_HEX[]                     = 
"013c01ff0001ffffffffffff0f029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd0880712101fed7951066f7f8be77db9a8beaeb45fa90ada12be9e5db2eda4a4b6c5fa46a9d";

const uint8_t  CURRENT_TRANSACTION_VERSION                   =  1;
const uint8_t  BLOCK_MAJOR_VERSION_1                         =  1;
const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        =  10000;  //by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            =  200;    //by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         =  1000;

//TODO This port will be used by the daemon to establish connections with p2p network
const int      P2P_DEFAULT_PORT                              = 59007;
//TODO This port will be used by the daemon to interact with simlewallet
const int      RPC_DEFAULT_PORT                              = 59008;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                =  1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 =  5000;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 16 * 1024 * 1024; // 16 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 8;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60;            // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 50000000;      // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;          // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000;          // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000;          // 5 seconds
const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "0000000000000000000000000000000000000000000000000000000000000000";

//TODO Add here your network seed nodes
const std::initializer_list<const char*> SEED_NODES = {
  "172.31.20.82:59007",
  "18.219.35.33:59007",
  "172.31.3.16:59007",
  "18.191.62.153:59007",
};

struct CheckpointData {
  uint32_t height;
  const char* blockId;
};

#ifdef __GNUC__
__attribute__((unused))
#endif

// You may add here other checkpoints using the following format:
// {<block height>, "<block hash>"},
const std::initializer_list<CheckpointData> CHECKPOINTS = {
{10000, "0000000000000000000000000000000000000000000000000000000000000000"},
 // {230580, "32bd7cb6c68a599cf2861941f29002a5e203522b9af54f08dfced316f6459103"},
//  {260000, "f68e70b360ca194f48084da7a7fd8e0251bbb4b5587f787ca65a6f5baf3f5947"},
//  {300000, "8e80861713f68354760dc10ea6ea79f5f3ff28f39b3f0835a8637463b09d70ff"},
 // {390285, "e00bdc9bf407aeace2f3109de11889ed25894bf194231d075eddaec838097eb7"},
//  {417000, "2dc96f8fc4d4a4d76b3ed06722829a7ab09d310584b8ecedc9b578b2c458a69f"},
 // {427193, "00feabb08f2d5759ed04fd6b799a7513187478696bba2db2af10d4347134e311"},
 // {453537, "d17de6916c5aa6ffcae575309c80b0f8fdcd0a84b5fa8e41a841897d4b5a4e97"},
//  {462250, "13468d210a5ec884cf839f0259f247ccf3efef0414ac45172033d32c739beb3e"},
//  {468000, "251bcbd398b1f593193a7210934a3d87f692b2cb0c45206150f59683dd7e9ba1"},
//  {480200, "363544ac9920c778b815c2fdbcbca70a0d79b21f662913a42da9b49e859f0e5b"},
 // {484500, "5cdf2101a0a62a0ab2a1ca0c15a6212b21f6dbdc42a0b7c0bcf65ca40b7a14fb"},
 // {506000, "3d54c1132f503d98d3f0d78bb46a4503c1a19447cb348361a2232e241cb45a3c"},
//  {544000, "f69dc61b6a63217f32fa64d5d0f9bd920873f57dfd79ebe1d7d6fb1345b56fe0"},
//  {553300, "f7a5076b887ce5f4bb95b2729c0edb6f077a463f04f1bffe7f5cb0b16bb8aa5f"},
 // {580000, "93aea06936fa4dc0a84c9109c9d5f0e1b0815f96898171e42fd2973d262ed9ac"},
 // {602000, "a05fd2fccbb5f567ece940ebb62a82fdb1517ff5696551ae704e5f0ef8edb979"},
//  {623000, "7c92dd374efd0221065c7d98fce0568a1a1c130b5da28bb3f338cdc367b93d0b"},
// {645000, "1eeba944c0dd6b9a1228a425a74076fbdbeaf9b657ba7ef02547d99f971de70d"},
//  {667000, "a020c8fcaa567845d04b520bb7ebe721e097a9bed2bdb8971081f933b5b42995"},
 // {689000, "212ec2698c5ebd15d6242d59f36c2d186d11bb47c58054f476dd8e6b1c7f0008"},
//  {713000, "a03f836c4a19f907cd6cac095eb6f56f5279ca2d1303fb7f826750dcb9025495"},
 // {750300, "5117631dbeb5c14748a91127a515ecbf13f6849e14fda7ee03cd55da41f1710c"},
//  {780000, "8dd55a9bae429e3685b90317281e633917023d3512eb7f37372209d1a5fc1070"},
 // {785500, "de1a487d70964d25ed6f7de196866f357a293e867ee81313e7fd0352d0126bdd"},
//  {789000, "acef490bbccce3b7b7ae8554a414f55413fbf4ca1472c6359b126a4439bd9f01"},
 // {796000, "04e387a00d35db21d4d93d04040b31f22573972a7e61d72cc07d0ab69bcb9c44"},
 // {800000, "d7fa4eea02e5ce60b949136569c0ea7ac71ea46e0065311054072ac415560b86"},
 // {804000, "bcc8b3782499aae508c40d5587d1cc5d68281435ea9bfc6804a262047f7b934d"},
 // {810500, "302b2349f221232820adc3dadafd8a61b035491e33af669c78a687949eb0a381"},
  //{816000, "32b7fdd4e4d715db81f8f09f4ba5e5c78e8113f2804d61a57378baee479ce745"},
 // {822000, "a3c9603c6813a0dc0efc40db288c356d1a7f02d1d2e47bee04346e73715f8984"},
 // {841000, "2cffb6504ee38f708a6256a63585f9382b3b426e64b4504236c70678bd160dce"},
 // {890000, "a7132932ea31236ce6b8775cd1380edf90b5e536ee4202c77b69a3d62445fcd2"},
  //{894000, "ae2624ea1472ecc36de0d812f21a32da2d4afc7d5770830083cbaf652209d316"},
 // {979000, "d8290eb4eedbe638f5dbadebcaf3ea434857ce96168185dc04f75b6cc1f4fda6"},
 // {985548, "8d53e0d97594755a621feaee0978c0431fc01f42b85ff76a03af8641e2009d57"},
 // {985549, "dc6f8d9319282475c981896b98ff9772ae2499533c2302c32faf65115aaf2554"},
 // {996000, "c9a9243049acc7773a3e58ae354d66f8ea83996ece93ffbaad0b8b42b5fb7223"},
 // {1021000, "a0c4107d327ffeb31dabe135a7124191b0a5ef7c4fa34f06babc1f0546ab938e"},
 // {1039000, "8c9208940fc92539fac98cc658b95d240635f8729ee8bd756d6bdbab52de2c04"},
 // {1170000, "f48441157749e89687dfa6edec2128ff332bdaa9eb139f2330a193e3139d2980"},
 // {1268000, "d49fcaec1d53095e2c244913f123bfd4b26eabb6d75aca7b77a00de8aa8ac680"},
//  {1272000, "2fb2c50328c8345d2f0a16b3ec4ea680a8a93730358494265ada9edbb9bfa1a6"},
 // {1273000, "496a9238c654d79c48d269224aa75d61f51831bae6dc744f5e709bec11c7c9f2"},
//  {1278000, "de0225cd279ca27cc8d4f8da1b5b92ba0112e48b3777b8c50301846ccfc9146b"},
 // {1283000, "826043db95e9801f038f254d223ce0d0912da269dcce1461b5f0f05ddfae9e1c"},
 // {1324000, "981e6f6871a7c295b56c5ce544adb5a7d52540ee23e15474b4357c7728952fef"},
 // {1329000, "b88ed8dfe95a19bd6377f77c01d87df9cf7bd14cd6de7ec616beca95deb1fc85"},
 // {1343000, "1696231b026b4e10412b16d65ba036c9750d287ab76da7e25efd4ba3fa9ed999"},
 // {1372000, "55e02f544df808a12d3c2809b8c7490f8b0729aef196745240e94522c69a7181"},
};
} // CryptoNote

#define ALLOW_DEBUG_COMMANDS
