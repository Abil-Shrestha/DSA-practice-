using System;
using System.Collections.Generic;
using http://System.Security.Cryptography;
using System.Text;

namespace HackersBlockChain
{
    public class Block
    {
        public int Index { get; set; }
        public DateTime Timestamp { get; set; }
        public string Data { get; set; }
        public string PreviousHash { get; set; }
        public string Hash { get; set; }

        public Block(DateTime timestamp, string data, string previousHash = "")
        {
            Index = 0;
            Timestamp = timestamp;
            Data = data;
            PreviousHash = previousHash;
            Hash = CalculateHash();
        }

        public string CalculateHash()
        {
            SHA256 sha256 = SHA256.Create();

            byte[] inputBytes = Encoding.ASCII.GetBytes($"{Timestamp}-{Data}-{PreviousHash}");
            byte[] outputBytes = sha256.ComputeHash(inputBytes);

            return Convert.ToBase64String(outputBytes);
        }
    }

    public class Blockchain
    {
        private List<Block> _chain;

        public Blockchain()
        {
            _chain = new List<Block> { CreateGenesisBlock() };
        }

        private Block CreateGenesisBlock()
        {
            return new Block(http://DateTime.Now, "Genesis Block", "0");
        }

        public Block GetLatestBlock()
        {
            return _chain[_chain.Count - 1];
        }

        public void AddBlock(Block block)
        {
            block.Index = _chain.Count;
            block.PreviousHash = GetLatestBlock().Hash;
            block.Hash = block.CalculateHash();
            _chain.Add(block);
        }

        public bool IsValid()
        {
            for (int i = 1; i < _chain.Count; i++)
            {
                Block currentBlock = _chain[i];
                Block previousBlock = _chain[i - 1];

                if (currentBlock.Hash != currentBlock.CalculateHash())
                {
                    return false;
                }

                if (currentBlock.PreviousHash != previousBlock.Hash)
                {
                    return false;
                }
            }

            return true;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Blockchain blockchain = new Blockchain();

            Block block1 = new Block(http://DateTime.Now, "Block 1 Data");
            blockchain.AddBlock(block1);

            Block block2 = new Block(http://DateTime.Now, "Block 2 Data");
            blockchain.AddBlock(block2);

            Console.WriteLine($"Is the blockchain valid? {blockchain.IsValid()}");

            http://block2.Data = "Modified Block 2 Data";
            Console.WriteLine($"Is the blockchain valid after tampering? {blockchain.IsValid()}");
        }
    }
}